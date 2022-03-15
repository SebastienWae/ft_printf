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
    sprintf(filebuf, "test.%s.log", uuid);

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
static void test_ft_printf_c_a(void **state)
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
    test_printf(" %c %c %c ", NULL, NULL, 77);
}

/* tests for %s */
static void test_ft_printf_s_empty(void **state)
{
    (void)state;
    test_printf(" %s ", "");
}
static void test_ft_printf_s_hello(void **state)
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

/* tests for %p */
static void test_ft_printf_p_one(void **state)
{
    (void)state;
    test_printf(" %p ", 1);
}
static void test_ft_printf_p_neg(void **state)
{
    (void)state;
    test_printf(" %p ", -1);
}
static void test_ft_printf_p_max(void **state)
{
    (void)state;
    test_printf(" %p ", ULONG_MAX);
}
static void test_ft_printf_p_5p(void **state)
{
    (void)state;
    test_printf(" %p %p %p %p %p ", 1, 2, 3, 4, 5);
}
static void test_ft_printf_p_nulls(void **state)
{
    (void)state;
#if defined __APPLE__
    test_printf(" %p %p %p ", NULL, NULL, NULL );
#endif
}

/* tests for %d */
static void test_ft_printf_d_zero(void **state)
{
    (void)state;
    test_printf(" %d ", 0);
}
static void test_ft_printf_d_one(void **state)
{
    (void)state;
    test_printf(" %d ", 1);
}
static void test_ft_printf_d_neg(void **state)
{
    (void)state;
    test_printf(" %d ", -1);
}
static void test_ft_printf_d_5d(void **state)
{
    (void)state;
    test_printf(" %d %d %d %d %d ", 1, 1234, 9482, 8, -134);
}
static void test_ft_printf_d_max(void **state)
{
    (void)state;
    test_printf(" %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}
static void test_ft_printf_d_nulls(void **state)
{
    (void)state;
    test_printf(" %d %d %d %d", NULL, 1, NULL);
}

/* tests for %d */
static void test_ft_printf_i_zero(void **state)
{
    (void)state;
    test_printf(" %i ", 0);
}
static void test_ft_printf_i_one(void **state)
{
    (void)state;
    test_printf(" %i ", 1);
}
static void test_ft_printf_i_neg(void **state)
{
    (void)state;
    test_printf(" %i ", -1);
}
static void test_ft_printf_i_5i(void **state)
{
    (void)state;
    test_printf(" %i %i %i %i %i ", 1, 1234, 9482, 8, -134);
}
static void test_ft_printf_i_max(void **state)
{
    (void)state;
    test_printf(" %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}
static void test_ft_printf_i_nulls(void **state)
{
    (void)state;
    test_printf(" %i %i %i %i", NULL, 1, NULL);
}

/* tests for %u */
static void test_ft_printf_u_zero(void **state)
{
    (void)state;
    test_printf(" %u ", 0);
}
static void test_ft_printf_u_one(void **state)
{
    (void)state;
    test_printf(" %u ", 1);
}
static void test_ft_printf_u_neg(void **state)
{
    (void)state;
    test_printf(" %u ", -1);
}
static void test_ft_printf_u_5u(void **state)
{
    (void)state;
    test_printf(" %u %u %u %u %u ", 1, 1234, 9482, 8, -134);
}
static void test_ft_printf_u_max(void **state)
{
    (void)state;
    test_printf(" %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}
static void test_ft_printf_u_nulls(void **state)
{
    (void)state;
    test_printf(" %u %u %u %u", NULL, 1, NULL);
}

/* tests for %x */
static void test_ft_printf_x_zero(void **state)
{
    (void)state;
    test_printf(" %x ", 0);
}
static void test_ft_printf_x_one(void **state)
{
    (void)state;
    test_printf(" %x ", 1);
}
static void test_ft_printf_x_neg(void **state)
{
    (void)state;
    test_printf(" %x ", -1);
}
static void test_ft_printf_x_5x(void **state)
{
    (void)state;
    test_printf(" %x %x %x %x %x ", 1, 1234, 9482, 8, -134);
}
static void test_ft_printf_x_max(void **state)
{
    (void)state;
    test_printf(" %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}
static void test_ft_printf_x_nulls(void **state)
{
    (void)state;
    test_printf(" %x %x %x %x", NULL, 1, NULL);
}

/* tests for %X */
static void test_ft_printf_X_zero(void **state)
{
    (void)state;
    test_printf(" %X ", 0);
}
static void test_ft_printf_X_one(void **state)
{
    (void)state;
    test_printf(" %X ", 1);
}
static void test_ft_printf_X_neg(void **state)
{
    (void)state;
    test_printf(" %X ", -1);
}
static void test_ft_printf_X_5X(void **state)
{
    (void)state;
    test_printf(" %X %X %X %X %X ", 1, 1234, 9482, 8, -134);
}
static void test_ft_printf_X_max(void **state)
{
    (void)state;
    test_printf(" %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN);
}
static void test_ft_printf_X_nulls(void **state)
{
    (void)state;
    test_printf(" %X %X %X %X", NULL, 1, NULL);
}

/* tests for %% */
static void test_ft_printf_perc1(void **state)
{
    (void)state;
    test_printf(" %% ");
}
static void test_ft_printf_perc2(void **state)
{
    (void)state;
    test_printf(" %%%% ");
}
static void test_ft_printf_perc3(void **state)
{
    (void)state;
    test_printf(" %% %% %% ");
}
static void test_ft_printf_perc4(void **state)
{
    (void)state;
    test_printf(" %%  %%  %% ");
}

/* mix tests */
static void test_ft_printf_mix1(void **state)
{
    (void)state;
    test_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
}
static void test_ft_printf_mix2(void **state)
{
    (void)state;
    test_printf("%%d%%d%X%% %% %d%u%i", 1, 2, 123); 
}

int main(void) {
    const struct CMUnitTest ft_printf_c_tests[] = {
        cmocka_unit_test(test_ft_printf_c_a),
        cmocka_unit_test(test_ft_printf_c_neg),
        cmocka_unit_test(test_ft_printf_c_5c),
        cmocka_unit_test(test_ft_printf_c_nulls),
    };
    cmocka_run_group_tests(ft_printf_c_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_s_tests[] = {
        cmocka_unit_test(test_ft_printf_s_empty),
        cmocka_unit_test(test_ft_printf_s_hello),
        cmocka_unit_test(test_ft_printf_s_hello_empty),
        cmocka_unit_test(test_ft_printf_s_empty_hello),
        cmocka_unit_test(test_ft_printf_s_5s),
        cmocka_unit_test(test_ft_printf_s_long),
        cmocka_unit_test(test_ft_printf_s_nulls),
    };
    cmocka_run_group_tests(ft_printf_s_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_p_tests[] = {
        cmocka_unit_test(test_ft_printf_p_one),
        cmocka_unit_test(test_ft_printf_p_neg),
        cmocka_unit_test(test_ft_printf_p_max),
        cmocka_unit_test(test_ft_printf_p_5p),
        cmocka_unit_test(test_ft_printf_p_nulls),
    };
    cmocka_run_group_tests(ft_printf_p_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_d_tests[] = {
        cmocka_unit_test(test_ft_printf_d_zero),
        cmocka_unit_test(test_ft_printf_d_one),
        cmocka_unit_test(test_ft_printf_d_neg),
        cmocka_unit_test(test_ft_printf_d_max),
        cmocka_unit_test(test_ft_printf_d_5d),
        cmocka_unit_test(test_ft_printf_d_nulls),
    };
    cmocka_run_group_tests(ft_printf_d_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_i_tests[] = {
        cmocka_unit_test(test_ft_printf_i_zero),
        cmocka_unit_test(test_ft_printf_i_one),
        cmocka_unit_test(test_ft_printf_i_neg),
        cmocka_unit_test(test_ft_printf_i_max),
        cmocka_unit_test(test_ft_printf_i_5i),
        cmocka_unit_test(test_ft_printf_i_nulls),
    };
    cmocka_run_group_tests(ft_printf_i_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_u_tests[] = {
        cmocka_unit_test(test_ft_printf_u_zero),
        cmocka_unit_test(test_ft_printf_u_one),
        cmocka_unit_test(test_ft_printf_u_neg),
        cmocka_unit_test(test_ft_printf_u_max),
        cmocka_unit_test(test_ft_printf_u_5u),
        cmocka_unit_test(test_ft_printf_u_nulls),
    };
    cmocka_run_group_tests(ft_printf_u_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_x_tests[] = {
        cmocka_unit_test(test_ft_printf_x_zero),
        cmocka_unit_test(test_ft_printf_x_one),
        cmocka_unit_test(test_ft_printf_x_neg),
        cmocka_unit_test(test_ft_printf_x_max),
        cmocka_unit_test(test_ft_printf_x_5x),
        cmocka_unit_test(test_ft_printf_x_nulls),
    };
    cmocka_run_group_tests(ft_printf_x_tests, NULL, NULL);
    
    const struct CMUnitTest ft_printf_X_tests[] = {
        cmocka_unit_test(test_ft_printf_X_zero),
        cmocka_unit_test(test_ft_printf_X_one),
        cmocka_unit_test(test_ft_printf_X_neg),
        cmocka_unit_test(test_ft_printf_X_max),
        cmocka_unit_test(test_ft_printf_X_5X),
        cmocka_unit_test(test_ft_printf_X_nulls),
    };
    cmocka_run_group_tests(ft_printf_X_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_perc_tests[] = {
        cmocka_unit_test(test_ft_printf_perc1),
        cmocka_unit_test(test_ft_printf_perc2),
        cmocka_unit_test(test_ft_printf_perc3),
        cmocka_unit_test(test_ft_printf_perc4),
    };
    cmocka_run_group_tests(ft_printf_perc_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_mix_tests[] = {
        cmocka_unit_test(test_ft_printf_mix1),
        cmocka_unit_test(test_ft_printf_mix2),
    };
    cmocka_run_group_tests(ft_printf_mix_tests, NULL, NULL);
}
