#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>

#include <ft_printf.h>

#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <stdarg.h>


#include <uuid/uuid.h>

char *file_out, *file_err;
int save_out, save_err;

static int watch_start_fd(int fd, char **filepath)
{
    uuid_t bid;
    uuid_generate_random(bid);

    char uuid[37];
    uuid_unparse_lower(bid, uuid);

    char filebuf[256];
    sprintf(filebuf, "criterion.%s.log", uuid);

    *filepath = strdup(filebuf);
    assert(*filepath != NULL);

    int new_fd = open(*filepath, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    assert(new_fd != -1);

    int save_fd = dup(fd);
    assert(save_fd != -1);

    int status = dup2(new_fd, fd);
    assert(status != -1);

    status = close(new_fd);
    assert(status != -1);

    return (save_fd);
}

static char *watch_stop_fd(int fd, char *filepath, int save_fd)
{
    int file_fd;
    char *content;
    struct stat s;
    int status;

    status = stat(filepath, &s);
    assert(status != -1);

    content = malloc(s.st_size + 1);
    assert(content != NULL);
    content[s.st_size] = '\0';
    
    file_fd = open(filepath, O_RDONLY);
    assert(file_fd != -1);

    ssize_t read_size = read(file_fd, content, s.st_size);
    assert(read_size >= 0);
    assert(read_size == s.st_size);

    status = close(file_fd);
    assert(status != -1);

    status = dup2(save_fd, fd);
    assert(status != -1);

    status = close(save_fd);
    assert(status != -1);

    status = remove(filepath);
    assert(status != -1);

    free(filepath);
    
    return (content);
}

static void watch_start(void)
{
    save_out = watch_start_fd(STDOUT_FILENO, &file_out);
    save_err = watch_start_fd(STDERR_FILENO, &file_err);
}

static void watch_stop(char **out, char **err)
{
    *out = watch_stop_fd(STDOUT_FILENO, file_out, save_out);
    *err = watch_stop_fd(STDERR_FILENO, file_err, save_err);
}

static void cr_assert_print_conversion(const char *fmt, ...)
{
    char *out, *err;
    char *sys_out, *sys_err;
    va_list ap;
    va_list sys_ap;
	t_flags	flags;

    va_start(ap, fmt);
	va_copy(sys_ap, ap);

    watch_start();
    int sys_len = vprintf(fmt, sys_ap);
	fflush(stdout);
    fflush(stderr);
    watch_stop(&sys_out, &sys_err);

    watch_start();
	flags = init_flags();
    int len = ft_print_conversion(&fmt, ap, flags);
    watch_stop(&out, &err);

    
    va_end(ap);

	cr_expect(eq(str, sys_out, out));
	//cr_expect(eq(str, sys_err, err));
	cr_expect(eq(i32, sys_len, len));

    free(err);
    free(out);
    free(sys_err);
    free(sys_out);
}

/* TEST: %c */
Test(ft_print_conversion_c, print_c) {
	cr_assert_print_conversion("%c", 'c');
}
Test(ft_print_conversion_c, print_1) {
	cr_assert_print_conversion("%c", 49);
}

/* TEST: %s */
Test(ft_print_conversion_s, print_hello) {
	cr_assert_print_conversion("%s", "hello");
}

/* TEST: %p */
Test(ft_print_conversion_p, print_null) {
    char    *ptr;

    ptr = 0;
	cr_assert_print_conversion("%p", ptr);
}
Test(ft_print_conversion_p, print_ptr) {
    char    ptr;

    ptr = 'a';
	cr_assert_print_conversion("%p", &ptr);
}

/* TEST: %d */
Test(ft_print_conversion_d, print_0) {
	cr_assert_print_conversion("%d", 0);
}
Test(ft_print_conversion_d, print_int_max) {
	cr_assert_print_conversion("%d", INT_MAX);
}
Test(ft_print_conversion_d, print_int_min) {
	cr_assert_print_conversion("%d", INT_MIN);
}

/* TEST: %i */
Test(ft_print_conversion_i, print_0) {
	cr_assert_print_conversion("%i", 0);
}
Test(ft_print_conversion_i, print_int_max) {
	cr_assert_print_conversion("%i", INT_MAX);
}
Test(ft_print_conversion_i, print_int_min) {
	cr_assert_print_conversion("%i", INT_MIN);
}

/* TEST: %u */
Test(ft_print_conversion_u, print_0) {
	cr_assert_print_conversion("%u", 0);
}
Test(ft_print_conversion_u, print_unsigned_max) {
	cr_assert_print_conversion("%u", UINT_MAX);
}
Test(ft_print_conversion_u, print_neg) {
	cr_assert_print_conversion("%u", -1);
}

/* TEST: %x */
Test(ft_print_conversion_x, print_0) {
	cr_assert_print_conversion("%x", 0);
}
Test(ft_print_conversion_x, print_unsigned_max) {
	cr_assert_print_conversion("%x", UINT_MAX);
}
Test(ft_print_conversion_x, print_neg) {
	cr_assert_print_conversion("%x", -1);
}

/* TEST: %X */
Test(ft_print_conversion_X, print_0) {
	cr_assert_print_conversion("%X", 0);
}
Test(ft_print_conversion_X, print_unsigned_max) {
	cr_assert_print_conversion("%X", UINT_MAX);
}
Test(ft_print_conversion_X, print_neg) {
	cr_assert_print_conversion("%X", -1);
}

/* TEST: %% */
Test(ft_print_conversion_other, print_percent) {
	cr_assert_print_conversion("%%", 123);
}

/* TEST: other char */
Test(ft_print_conversion_other, print_y) {
	cr_assert_print_conversion("%y", 123);
}
