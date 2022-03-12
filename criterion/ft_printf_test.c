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

static void cr_assert_printf(const char *fmt, ...)
{
    char *out, *err;
    char *sys_out, *sys_err;
    va_list ap;
    va_list sys_ap;

    va_start(ap, fmt);
	va_copy(sys_ap, ap);

    watch_start();
    int sys_len = vprintf(fmt, sys_ap);
	fflush(stdout);
    fflush(stderr);
    watch_stop(&sys_out, &sys_err);

    watch_start();
    int len = ft_vprintf(fmt, ap); 
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
Test(ft_printf, print_c) {
	cr_assert_printf("%c", 'c');
}
