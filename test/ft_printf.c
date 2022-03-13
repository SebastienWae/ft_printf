#include <ft_printf.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <stdarg.h>
#include <uuid/uuid.h>

#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

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

static void test_printf(char *fmt, ...)
{
    char *out, *err;
    char *sys_out, *sys_err;
    va_list ap;
    va_list sys_ap;

    va_start(ap, fmt);
	va_copy(sys_ap, ap);

    watch_start();
    int len = ft_vprintf(fmt, ap);
    watch_stop(&out, &err);

    watch_start();
    int sys_len = vprintf(fmt, sys_ap);
	fflush(stdout);
    fflush(stderr);
    watch_stop(&sys_out, &sys_err);

    assert_string_equal(out, sys_out);
    assert_string_equal(err, sys_err);
    assert_int_equal(len, sys_len);

    free(err);
    free(out);
    free(sys_err);
    free(sys_out);
}

/* tests for %c */
static void test_ft_printf_c_missing(void **state)
{
    (void)state;
    test_printf("%c");
}
static void test_ft_printf_c_a_no_spaces(void **state)
{
    (void)state;
    test_printf("%c", 'a');
}
static void test_ft_printf_c_a_space_before(void **state)
{
    (void)state;
    test_printf(" %c", 'a');
}
static void test_ft_printf_c_a_space_after(void **state)
{
    (void)state;
    test_printf("%c ", 'a');
}
static void test_ft_printf_c_a_space_arround(void **state)
{
    (void)state;
    test_printf(" %c ", 'a');
}
static void test_ft_printf_c_neg(void **state)
{
    (void)state;
    test_printf(" %c ", -127);
}
static void test_ft_printf_c_5c(void **state)
{
    (void)state;
    test_printf(" %c %c %c %c %c ", 1, 'T', -12, 'x', ' ');
}
static void test_ft_printf_c_nulls(void **state)
{
    (void)state;
    test_printf("%c %c %c", NULL, NULL, 77);
}

/* tests for %s */
static void test_ft_printf_s_missing(void **state)
{
    (void)state;
    test_printf("%s");
}
static void test_ft_printf_s_empty_no_spaces(void **state)
{
    (void)state;
    test_printf("%s", "");
}
static void test_ft_printf_s_empty_space_before(void **state)
{
    (void)state;
    test_printf(" %s", "");
}
static void test_ft_printf_s_empty_space_after(void **state)
{
    (void)state;
    test_printf("%s ", "");
}
static void test_ft_printf_s_empty_space_around(void **state)
{
    (void)state;
    test_printf(" %s ", "");
}
static void test_ft_printf_s_hello_space_around(void **state)
{
    (void)state;
    test_printf(" %s ", "hello");
}
static void test_ft_printf_s_hello_empty(void **state)
{
    (void)state;
    test_printf(" %s %s ", "hello", "");
}
static void test_ft_printf_s_empty_hello(void **state)
{
    (void)state;
    test_printf(" %s %s ", "", "hello");
}
static void test_ft_printf_s_5s(void **state)
{
    (void)state;
    test_printf(" %s %s %s %s %s", "", "hello", "  ", "123", "");
}
static void test_ft_printf_s_long(void **state)
{
    char    *s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean rhoncus dapibus placerat. Suspendisse pretium viverra tincidunt. Vivamus id justo a lectus sollicitudin laoreet vel ac purus. Etiam dui est, placerat vel dui congue, posuere lacinia diam. Nullam aliquet dictum orci sit amet vehicula. Fusce hendrerit venenatis malesuada. Morbi elementum massa sit amet tincidunt sagittis. Aliquam risus dui, imperdiet at dui sit amet, dignissim sollicitudin velit. Nam varius ante neque, ut feugiat neque placerat sed.";
    (void)state;
    test_printf(" %s %s %s %s %s", "", "hello", "  ", "123", s);
}
static void test_ft_printf_s_nulls(void **state)
{
    (void)state;
    test_printf(" %s %s %s %s", "", NULL, NULL, "123");
}

int main(void) {
    const struct CMUnitTest ft_printf_c_tests[] = {
        cmocka_unit_test(test_ft_printf_c_missing),
        cmocka_unit_test(test_ft_printf_c_a_no_spaces),
        cmocka_unit_test(test_ft_printf_c_a_space_before),
        cmocka_unit_test(test_ft_printf_c_a_space_after),
        cmocka_unit_test(test_ft_printf_c_a_space_arround),
        cmocka_unit_test(test_ft_printf_c_neg),
        cmocka_unit_test(test_ft_printf_c_5c),
        cmocka_unit_test(test_ft_printf_c_nulls),
    };
    cmocka_run_group_tests(ft_printf_c_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_s_tests[] = {
        cmocka_unit_test(test_ft_printf_s_missing),
        cmocka_unit_test(test_ft_printf_s_empty_no_spaces),
        cmocka_unit_test(test_ft_printf_s_empty_space_before),
        cmocka_unit_test(test_ft_printf_s_empty_space_after),
        cmocka_unit_test(test_ft_printf_s_empty_space_around),
        cmocka_unit_test(test_ft_printf_s_hello_space_around),
        cmocka_unit_test(test_ft_printf_s_hello_empty),
        cmocka_unit_test(test_ft_printf_s_empty_hello),
        cmocka_unit_test(test_ft_printf_s_5s),
        cmocka_unit_test(test_ft_printf_s_long),
        cmocka_unit_test(test_ft_printf_s_nulls),
    };
    cmocka_run_group_tests(ft_printf_s_tests, NULL, NULL);
}
