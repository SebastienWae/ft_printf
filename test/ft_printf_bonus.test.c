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
    //save_err = watch_start_fd(STDERR_FILENO, &file_err);
}

static void watch_stop(char **out, char **err)
{
    *out = watch_stop_fd(STDOUT_FILENO, file_out, save_out);
    (void)err;
    //*err = watch_stop_fd(STDERR_FILENO, file_err, save_err);
}

#define TEST_PRINTF(f, ...) \
        char *out, *err; \
        char *sys_out, *sys_err; \
        watch_start(); \
        int len = ft_printf(f, ## __VA_ARGS__); \
        watch_stop(&out, &err); \
        watch_start(); \
        int sys_len = printf(f, ## __VA_ARGS__); \
        fflush(stdout); \
        watch_stop(&sys_out, &sys_err); \
        assert_string_equal(out, sys_out); \
        assert_int_equal(len, sys_len); \
        free(out); \
        free(sys_out);

/* tests for + */
static void test_ft_printf_plus_d_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %+d ", 0);
}
static void test_ft_printf_plus_d_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %+d ", -1);
}
static void test_ft_printf_plus_d_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %+d ", INT_MAX);
}
static void test_ft_printf_plus_d_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" %+d ", INT_MIN);
}
static void test_ft_printf_plus_d_multi(void **state)
{
    (void)state;
    TEST_PRINTF(" %+d %+d %d %+d ", 1, 23456, -46453, 0);
}
static void test_ft_printf_plus_i_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %+i ", 0);
}
static void test_ft_printf_plus_i_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %+i ", -1);
}
static void test_ft_printf_plus_i_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %+i ", INT_MAX);
}
static void test_ft_printf_plus_i_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" %+i ", INT_MIN);
}
static void test_ft_printf_plus_i_multi(void **state)
{
    (void)state;
    TEST_PRINTF(" %+i %+i %i %+i ", 1, 23456, -46453, 0);
}

/* tests for ' ' */
static void test_ft_printf_space_d_0(void **state)
{
    (void)state;
    TEST_PRINTF(" % d ", 0);
}
static void test_ft_printf_space_d_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" % d ", -1);
}
static void test_ft_printf_space_d_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" % d ", INT_MAX);
}
static void test_ft_printf_space_d_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" % d ", INT_MIN);
}
static void test_ft_printf_space_d_multi(void **state)
{
    (void)state;
    TEST_PRINTF(" % d % d %d % d ", 1, 23456, -46453, 0);
}
static void test_ft_printf_space_i_0(void **state)
{
    (void)state;
    TEST_PRINTF(" % i ", 0);
}
static void test_ft_printf_space_i_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" % i ", -1);
}
static void test_ft_printf_space_i_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" % i ", INT_MAX);
}
static void test_ft_printf_space_i_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" % i ", INT_MIN);
}
static void test_ft_printf_space_i_multi(void **state)
{
    (void)state;
    TEST_PRINTF(" % i % i %i % i ", 1, 23456, -46453, 0);
}

/* tests for # */
static void test_ft_printf_hash_x_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %#x ", 0);
}
static void test_ft_printf_hash_x_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %#x ", -1);
}
static void test_ft_printf_hash_x_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %#x ", UINT_MAX);
}
static void test_ft_printf_hash_x_multi(void **state)
{
    (void)state;
    TEST_PRINTF(" %#x %#x %x %#x ", 1, 23456, -46453, 0);
}
static void test_ft_printf_hash_X_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %#X ", 0);
}
static void test_ft_printf_hash_X_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %#X ", -1);
}
static void test_ft_printf_hash_X_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %#X ", UINT_MAX);
}
static void test_ft_printf_hash_X_multi(void **state)
{
    (void)state;
    TEST_PRINTF(" %#X %#X %X %#X ", 1, 23456, -46453, 0);
}

/* tests for . */
static void test_ft_printf_dot_s_zero_empty(void **state)
{
    (void)state;
    TEST_PRINTF("%.s", "");
}
static void test_ft_printf_dot_s_one_empty(void **state)
{
    (void)state;
    TEST_PRINTF("%.1s", "");
}
static void test_ft_printf_dot_s_zero_hello(void **state)
{
    (void)state;
    TEST_PRINTF("%.0s", "hello");
}
static void test_ft_printf_dot_s_one_hello(void **state)
{
    (void)state;
    TEST_PRINTF("%.1s", "hello");
}
static void test_ft_printf_dot_s_multi(void **state)
{
    (void)state;
    TEST_PRINTF("%.4s %.10s %.s %.2s", "hello", "", " ", "this is a test") ;
}
static void test_ft_printf_dot_d_0_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.d ", 0);
}
static void test_ft_printf_dot_d_1_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1d ", 0);
}
static void test_ft_printf_dot_d_22_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22d ", 0);
}
static void test_ft_printf_dot_d_0_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.d ", -1);
}
static void test_ft_printf_dot_d_1_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1d ", -1);
}
static void test_ft_printf_dot_d_22_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22d ", -1);
}
static void test_ft_printf_dot_d_0_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.d ", INT_MAX);
}
static void test_ft_printf_dot_d_1_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1d ", INT_MAX);
}
static void test_ft_printf_dot_d_22_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22d ", INT_MAX);
}
static void test_ft_printf_dot_d_0_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" %.d ", INT_MIN);
}
static void test_ft_printf_dot_d_1_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1d ", INT_MIN);
}
static void test_ft_printf_dot_d_22_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22d ", INT_MIN);
}
static void test_ft_printf_dot_d_multi(void **state)
{
    (void)state;
    TEST_PRINTF("%.4d %.10d %.d %.2d", 1, 431, 0, -4256);
}
static void test_ft_printf_dot_i_0_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.i ", 0);
}
static void test_ft_printf_dot_i_1_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1i ", 0);
}
static void test_ft_printf_dot_i_22_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22i ", 0);
}
static void test_ft_printf_dot_i_0_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.i ", -1);
}
static void test_ft_printf_dot_i_1_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1i ", -1);
}
static void test_ft_printf_dot_i_22_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22i ", -1);
}
static void test_ft_printf_dot_i_0_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.i ", INT_MAX);
}
static void test_ft_printf_dot_i_1_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1i ", INT_MAX);
}
static void test_ft_printf_dot_i_22_INT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22i ", INT_MAX);
}
static void test_ft_printf_dot_i_0_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" %.i ", INT_MIN);
}
static void test_ft_printf_dot_i_1_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1i ", INT_MIN);
}
static void test_ft_printf_dot_i_22_INT_MIN(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22i ", INT_MIN);
}
static void test_ft_printf_dot_i_multi(void **state)
{
    (void)state;
    TEST_PRINTF("%.4i %.10i %.i %.2i", 1, 431, 0, -4256);
}
static void test_ft_printf_dot_u_0_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.u ", 0);
}
static void test_ft_printf_dot_u_1_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1u ", 0);
}
static void test_ft_printf_dot_u_22_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22u ", 0);
}
static void test_ft_printf_dot_u_0_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.u ", -1);
}
static void test_ft_printf_dot_u_1_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1u ", -1);
}
static void test_ft_printf_dot_u_22_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22u ", -1);
}
static void test_ft_printf_dot_u_0_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.u ", UINT_MAX);
}
static void test_ft_printf_dot_u_1_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1u ", UINT_MAX);
}
static void test_ft_printf_dot_u_22_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22u ", UINT_MAX);
}
static void test_ft_printf_dot_u_multi(void **state)
{
    (void)state;
    TEST_PRINTF("%.4u %.10u %.u %.2u", 1, 431, 0, -4256);
}
static void test_ft_printf_dot_x_0_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.x ", 0);
}
static void test_ft_printf_dot_x_1_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1x ", 0);
}
static void test_ft_printf_dot_x_22_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22x ", 0);
}
static void test_ft_printf_dot_x_0_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.x ", -1);
}
static void test_ft_printf_dot_x_1_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1x ", -1);
}
static void test_ft_printf_dot_x_22_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22x ", -1);
}
static void test_ft_printf_dot_x_0_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.x ", UINT_MAX);
}
static void test_ft_printf_dot_x_1_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1x ", UINT_MAX);
}
static void test_ft_printf_dot_x_22_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22x ", UINT_MAX);
}
static void test_ft_printf_dot_x_multi(void **state)
{
    (void)state;
    TEST_PRINTF("%.4x %.10x %.x %.2x", 1, 431, 0, -4256);
}
static void test_ft_printf_dot_X_0_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.X ", 0);
}
static void test_ft_printf_dot_X_1_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1X ", 0);
}
static void test_ft_printf_dot_X_22_0(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22X ", 0);
}
static void test_ft_printf_dot_X_0_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.X ", -1);
}
static void test_ft_printf_dot_X_1_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1X ", -1);
}
static void test_ft_printf_dot_X_22_neg(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22X ", -1);
}
static void test_ft_printf_dot_X_0_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.X ", UINT_MAX);
}
static void test_ft_printf_dot_X_1_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.1X ", UINT_MAX);
}
static void test_ft_printf_dot_X_22_UINT_MAX(void **state)
{
    (void)state;
    TEST_PRINTF(" %.22X ", UINT_MAX);
}
static void test_ft_printf_dot_X_multi(void **state)
{
    (void)state;
    TEST_PRINTF("%.4X %.10X %.X %.2X", 1, 431, 0, -4256);
}

/* tests for width/0/- */
static void test_ft_printf_width_0_c(void **state) {
    (void)state;
    TEST_PRINTF(" %0c ", 'c');
}
static void test_ft_printf_width_1_c(void **state)
{
    (void)state;
    TEST_PRINTF(" %1c ", 'c');
}
static void test_ft_printf_width_22_c(void **state)
{
    (void)state;
    TEST_PRINTF(" %22c ", 'c');
}
static void test_ft_printf_width_0_1_c(void **state)
{
    (void)state;
    TEST_PRINTF(" %01c ", 'c');
}
static void test_ft_printf_width_0_22_c(void **state)
{
    (void)state;
    TEST_PRINTF(" %022c ", 'c');
}
static void test_ft_printf_width_neg_0_c(void **state)
{
    (void)state;
    TEST_PRINTF(" %-0c ", 'c');
}
static void test_ft_printf_width_neg_1_c(void **state)
{
    (void)state;
    TEST_PRINTF(" %-1c ", 'c');
}
static void test_ft_printf_width_neg_22_c(void **state)
{
    (void)state;
    TEST_PRINTF(" %-22c ", 'c');
}
static void test_ft_printf_width_0_empty_s(void **state) {
    (void)state;
    TEST_PRINTF(" %0s ", "");
}
static void test_ft_printf_width_0_hello_s(void **state) {
    (void)state;
    TEST_PRINTF(" %0s ", "hello");
}
static void test_ft_printf_width_1_empty_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %1s ", "");
}
static void test_ft_printf_width_1_hello_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %1s ", "hello");
}
static void test_ft_printf_width_22_empty_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %22s ", "");
}
static void test_ft_printf_width_22_hello_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %22s ", "hello");
}
static void test_ft_printf_width_0_1_empty_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %01s ", "");
}
static void test_ft_printf_width_0_1_hello_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %01s ", "hello");
}
static void test_ft_printf_width_0_22_empty_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %022s ", "");
}
static void test_ft_printf_width_0_22_hello_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %022s ", "hello");
}
static void test_ft_printf_width_neg_0_empty_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %-0s ", "");
}
static void test_ft_printf_width_neg_0_hello_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %-0s ", "hello");
}
static void test_ft_printf_width_neg_1_empty_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %-1s ", "");
}
static void test_ft_printf_width_neg_1_hello_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %-1s ", "hello");
}
static void test_ft_printf_width_neg_22_empty_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %-22s ", "");
}
static void test_ft_printf_width_neg_22_hello_s(void **state)
{
    (void)state;
    TEST_PRINTF(" %-22s ", "hello");
}
static void test_ft_printf_width_0_0_p(void **state) {
    (void)state;
    TEST_PRINTF(" %0p ", 0);
}
static void test_ft_printf_width_0_ptr_p(void **state) {
    char    a;
    a = 1;
    (void)state;
    TEST_PRINTF(" %0p ", &a);
}
static void test_ft_printf_width_1_0_p(void **state)
{
    (void)state;
    TEST_PRINTF(" %1p ", 0);
}
static void test_ft_printf_width_1_ptr_p(void **state)
{
    char    a;
    a = 1;
    (void)state;
    TEST_PRINTF(" %1p ", &a);
}
static void test_ft_printf_width_22_0_p(void **state)
{
    (void)state;
    TEST_PRINTF(" %22p ", 0);
}
static void test_ft_printf_width_22_ptr_p(void **state)
{
    char    a;
    a = 1;
    (void)state;
    TEST_PRINTF(" %22p ", &a);
}
static void test_ft_printf_width_0_1_0_p(void **state)
{
    (void)state;
    TEST_PRINTF(" %01p ", 0);
}
static void test_ft_printf_width_0_1_ptr_p(void **state)
{
    char    a;
    a = 1;
    (void)state;
    TEST_PRINTF(" %01p ", &a);
}
static void test_ft_printf_width_0_22_0_p(void **state)
{
    (void)state;
    TEST_PRINTF(" %022p ", 0);
}
static void test_ft_printf_width_0_22_ptr_p(void **state)
{
    char    a;
    a = 1;
    (void)state;
    TEST_PRINTF(" %022p ", &a);
}
static void test_ft_printf_width_neg_0_0_p(void **state)
{
    (void)state;
    TEST_PRINTF(" %-0p ", 0);
}
static void test_ft_printf_width_neg_0_ptr_p(void **state)
{
    char    a;
    a = 1;
    (void)state;
    TEST_PRINTF(" %-0p ", &a);
}
static void test_ft_printf_width_neg_1_0_p(void **state)
{
    (void)state;
    TEST_PRINTF(" %-1p ", 0);
}
static void test_ft_printf_width_neg_1_ptr_p(void **state)
{
    char    a;
    a = 1;
    (void)state;
    TEST_PRINTF(" %-1p ", &a);
}
static void test_ft_printf_width_neg_22_0_p(void **state)
{
    (void)state;
    TEST_PRINTF(" %-22p ", 0);
}
static void test_ft_printf_width_neg_22_ptr_p(void **state)
{
    char    a;
    a = 1;
    (void)state;
    TEST_PRINTF(" %-22p ", &a);
}
static void test_ft_printf_width_0_0_d(void **state) {
    (void)state;
    TEST_PRINTF(" %0d ", 0);
}
static void test_ft_printf_width_0_neg_d(void **state) {
    (void)state;
    TEST_PRINTF(" %0d ", -1);
}
static void test_ft_printf_width_0_INT_MAX_d(void **state) {
    (void)state;
    TEST_PRINTF(" %0d ", INT_MAX);
}
static void test_ft_printf_width_0_INT_MIN_d(void **state) {
    (void)state;
    TEST_PRINTF(" %0d ", INT_MIN);
}
static void test_ft_printf_width_1_0_d(void **state) {
    (void)state;
    TEST_PRINTF(" %1d ", 0);
}
static void test_ft_printf_width_1_neg_d(void **state) {
    (void)state;
    TEST_PRINTF(" %1d ", -1);
}
static void test_ft_printf_width_1_INT_MAX_d(void **state) {
    (void)state;
    TEST_PRINTF(" %1d ", INT_MAX);
}
static void test_ft_printf_width_1_INT_MIN_d(void **state) {
    (void)state;
    TEST_PRINTF(" %1d ", INT_MIN);
}
static void test_ft_printf_width_22_0_d(void **state) {
    (void)state;
    TEST_PRINTF(" %22d ", 0);
}
static void test_ft_printf_width_22_neg_d(void **state) {
    (void)state;
    TEST_PRINTF(" %22d ", -1);
}
static void test_ft_printf_width_22_INT_MAX_d(void **state) {
    (void)state;
    TEST_PRINTF(" %22d ", INT_MAX);
}
static void test_ft_printf_width_22_INT_MIN_d(void **state) {
    (void)state;
    TEST_PRINTF(" %22d ", INT_MIN);
}
static void test_ft_printf_width_0_1_0_d(void **state) {
    (void)state;
    TEST_PRINTF(" %01d ", 0);
}
static void test_ft_printf_width_0_1_neg_d(void **state) {
    (void)state;
    TEST_PRINTF(" %01d ", -1);
}
static void test_ft_printf_width_0_1_INT_MAX_d(void **state) {
    (void)state;
    TEST_PRINTF(" %01d ", INT_MAX);
}
static void test_ft_printf_width_0_1_INT_MIN_d(void **state) {
    (void)state;
    TEST_PRINTF(" %01d ", INT_MIN);
}
static void test_ft_printf_width_0_22_0_d(void **state) {
    (void)state;
    TEST_PRINTF(" %022d ", 0);
}
static void test_ft_printf_width_0_22_neg_d(void **state) {
    (void)state;
    TEST_PRINTF(" %022d ", -1);
}
static void test_ft_printf_width_0_22_INT_MAX_d(void **state) {
    (void)state;
    TEST_PRINTF(" %022d ", INT_MAX);
}
static void test_ft_printf_width_0_22_INT_MIN_d(void **state) {
    (void)state;
    TEST_PRINTF(" %022d ", INT_MIN);
}
static void test_ft_printf_width_neg_0_0_d(void **state) {
    (void)state;
    TEST_PRINTF(" %-0d ", 0);
}
static void test_ft_printf_width_neg_0_neg_d(void **state) {
    (void)state;
    TEST_PRINTF(" %-0d ", -1);
}
static void test_ft_printf_width_neg_0_INT_MAX_d(void **state) {
    (void)state;
    TEST_PRINTF(" %-0d ", INT_MAX);
}
static void test_ft_printf_width_neg_0_INT_MIN_d(void **state) {
    (void)state;
    TEST_PRINTF(" %-0d ", INT_MIN);
}
static void test_ft_printf_width_neg_1_0_d(void **state)
{
    (void)state;
    TEST_PRINTF(" %-1d ", 0);
}
static void test_ft_printf_width_neg_1_neg_d(void **state)
{
    (void)state;
    TEST_PRINTF(" %-1d ", -1);
}
static void test_ft_printf_width_neg_1_INT_MAX_d(void **state)
{
    (void)state;
    TEST_PRINTF(" %-1d ", INT_MAX);
}
static void test_ft_printf_width_neg_1_INT_MIN_d(void **state)
{
    (void)state;
    TEST_PRINTF(" %-1d ", INT_MIN);
}
static void test_ft_printf_width_neg_22_0_d(void **state)
{
    (void)state;
    TEST_PRINTF(" %-22d ", 0);
}
static void test_ft_printf_width_neg_22_neg_d(void **state)
{
    (void)state;
    TEST_PRINTF(" %-22d ", -1);
}
static void test_ft_printf_width_neg_22_INT_MAX_d(void **state)
{
    (void)state;
    TEST_PRINTF(" %-22d ", INT_MAX);
}
static void test_ft_printf_width_neg_22_INT_MIN_d(void **state)
{
    (void)state;
    TEST_PRINTF(" %-22d ", INT_MIN);
}

int main(void) {
    const struct CMUnitTest ft_printf_plus_tests[] = {
        cmocka_unit_test(test_ft_printf_plus_d_0),
        cmocka_unit_test(test_ft_printf_plus_d_neg),
        cmocka_unit_test(test_ft_printf_plus_d_INT_MAX),
        cmocka_unit_test(test_ft_printf_plus_d_INT_MIN),
        cmocka_unit_test(test_ft_printf_plus_d_multi),
        cmocka_unit_test(test_ft_printf_plus_i_0),
        cmocka_unit_test(test_ft_printf_plus_i_neg),
        cmocka_unit_test(test_ft_printf_plus_i_INT_MAX),
        cmocka_unit_test(test_ft_printf_plus_i_INT_MIN),
        cmocka_unit_test(test_ft_printf_plus_i_multi),
    };
    cmocka_run_group_tests(ft_printf_plus_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_space_tests[] = {
        cmocka_unit_test(test_ft_printf_space_d_0),
        cmocka_unit_test(test_ft_printf_space_d_neg),
        cmocka_unit_test(test_ft_printf_space_d_INT_MAX),
        cmocka_unit_test(test_ft_printf_space_d_INT_MIN),
        cmocka_unit_test(test_ft_printf_space_d_multi),
        cmocka_unit_test(test_ft_printf_space_i_0),
        cmocka_unit_test(test_ft_printf_space_i_neg),
        cmocka_unit_test(test_ft_printf_space_i_INT_MAX),
        cmocka_unit_test(test_ft_printf_space_i_INT_MIN),
        cmocka_unit_test(test_ft_printf_space_i_multi),
    };
    cmocka_run_group_tests(ft_printf_space_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_hash_tests[] = {
        cmocka_unit_test(test_ft_printf_hash_x_0),
        cmocka_unit_test(test_ft_printf_hash_x_neg),
        cmocka_unit_test(test_ft_printf_hash_x_UINT_MAX),
        cmocka_unit_test(test_ft_printf_hash_x_multi),
        cmocka_unit_test(test_ft_printf_hash_X_0),
        cmocka_unit_test(test_ft_printf_hash_X_neg),
        cmocka_unit_test(test_ft_printf_hash_X_UINT_MAX),
        cmocka_unit_test(test_ft_printf_hash_X_multi),
    };
    cmocka_run_group_tests(ft_printf_hash_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_dot_tests[] = {
        cmocka_unit_test(test_ft_printf_dot_s_zero_empty),
        cmocka_unit_test(test_ft_printf_dot_s_one_empty),
        cmocka_unit_test(test_ft_printf_dot_s_zero_hello),
        cmocka_unit_test(test_ft_printf_dot_s_one_hello),
        cmocka_unit_test(test_ft_printf_dot_s_multi),
        cmocka_unit_test(test_ft_printf_dot_d_0_0),
        cmocka_unit_test(test_ft_printf_dot_d_1_0),
        cmocka_unit_test(test_ft_printf_dot_d_22_0),
        cmocka_unit_test(test_ft_printf_dot_d_0_neg),
        cmocka_unit_test(test_ft_printf_dot_d_1_neg),
        cmocka_unit_test(test_ft_printf_dot_d_22_neg),
        cmocka_unit_test(test_ft_printf_dot_d_0_INT_MAX),
        cmocka_unit_test(test_ft_printf_dot_d_1_INT_MAX),
        cmocka_unit_test(test_ft_printf_dot_d_22_INT_MAX),
        cmocka_unit_test(test_ft_printf_dot_d_0_INT_MIN),
        cmocka_unit_test(test_ft_printf_dot_d_1_INT_MIN),
        cmocka_unit_test(test_ft_printf_dot_d_22_INT_MIN),
        cmocka_unit_test(test_ft_printf_dot_d_multi),   
        cmocka_unit_test(test_ft_printf_dot_i_0_0),
        cmocka_unit_test(test_ft_printf_dot_i_1_0),
        cmocka_unit_test(test_ft_printf_dot_i_22_0),
        cmocka_unit_test(test_ft_printf_dot_i_0_neg),
        cmocka_unit_test(test_ft_printf_dot_i_1_neg),
        cmocka_unit_test(test_ft_printf_dot_i_22_neg),
        cmocka_unit_test(test_ft_printf_dot_i_0_INT_MAX),
        cmocka_unit_test(test_ft_printf_dot_i_1_INT_MAX),
        cmocka_unit_test(test_ft_printf_dot_i_22_INT_MAX),
        cmocka_unit_test(test_ft_printf_dot_i_0_INT_MIN),
        cmocka_unit_test(test_ft_printf_dot_i_1_INT_MIN),
        cmocka_unit_test(test_ft_printf_dot_i_22_INT_MIN),
        cmocka_unit_test(test_ft_printf_dot_i_multi),
        cmocka_unit_test(test_ft_printf_dot_u_0_0),
        cmocka_unit_test(test_ft_printf_dot_u_1_0),
        cmocka_unit_test(test_ft_printf_dot_u_22_0),
        cmocka_unit_test(test_ft_printf_dot_u_0_neg),
        cmocka_unit_test(test_ft_printf_dot_u_1_neg),
        cmocka_unit_test(test_ft_printf_dot_u_22_neg),
        cmocka_unit_test(test_ft_printf_dot_u_0_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_u_1_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_u_22_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_u_multi),
        cmocka_unit_test(test_ft_printf_dot_x_0_0),
        cmocka_unit_test(test_ft_printf_dot_x_1_0),
        cmocka_unit_test(test_ft_printf_dot_x_22_0),
        cmocka_unit_test(test_ft_printf_dot_x_0_neg),
        cmocka_unit_test(test_ft_printf_dot_x_1_neg),
        cmocka_unit_test(test_ft_printf_dot_x_22_neg),
        cmocka_unit_test(test_ft_printf_dot_x_0_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_x_1_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_x_22_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_x_multi),
        cmocka_unit_test(test_ft_printf_dot_X_0_0),
        cmocka_unit_test(test_ft_printf_dot_X_1_0),
        cmocka_unit_test(test_ft_printf_dot_X_22_0),
        cmocka_unit_test(test_ft_printf_dot_X_0_neg),
        cmocka_unit_test(test_ft_printf_dot_X_1_neg),
        cmocka_unit_test(test_ft_printf_dot_X_22_neg),
        cmocka_unit_test(test_ft_printf_dot_X_0_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_X_1_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_X_22_UINT_MAX),
        cmocka_unit_test(test_ft_printf_dot_X_multi),
    };
    cmocka_run_group_tests(ft_printf_dot_tests, NULL, NULL);

    const struct CMUnitTest ft_printf_width_tests[] = {
        cmocka_unit_test(test_ft_printf_width_0_c),
        cmocka_unit_test(test_ft_printf_width_1_c),
        cmocka_unit_test(test_ft_printf_width_22_c),
        cmocka_unit_test(test_ft_printf_width_0_1_c),
        cmocka_unit_test(test_ft_printf_width_neg_0_c),
        cmocka_unit_test(test_ft_printf_width_neg_1_c),
        cmocka_unit_test(test_ft_printf_width_neg_22_c),
        cmocka_unit_test(test_ft_printf_width_0_empty_s),
        cmocka_unit_test(test_ft_printf_width_0_hello_s),
        cmocka_unit_test(test_ft_printf_width_1_empty_s),
        cmocka_unit_test(test_ft_printf_width_1_hello_s),
        cmocka_unit_test(test_ft_printf_width_22_empty_s),
        cmocka_unit_test(test_ft_printf_width_22_hello_s),
        cmocka_unit_test(test_ft_printf_width_0_1_empty_s),
        cmocka_unit_test(test_ft_printf_width_0_1_hello_s),
        cmocka_unit_test(test_ft_printf_width_neg_0_empty_s),
        cmocka_unit_test(test_ft_printf_width_neg_0_hello_s),
        cmocka_unit_test(test_ft_printf_width_neg_1_empty_s),
        cmocka_unit_test(test_ft_printf_width_neg_1_hello_s),
        cmocka_unit_test(test_ft_printf_width_neg_22_empty_s),
        cmocka_unit_test(test_ft_printf_width_neg_22_hello_s),
        cmocka_unit_test(test_ft_printf_width_0_0_p),
        cmocka_unit_test(test_ft_printf_width_0_ptr_p),
        cmocka_unit_test(test_ft_printf_width_1_0_p),
        cmocka_unit_test(test_ft_printf_width_1_ptr_p),
        cmocka_unit_test(test_ft_printf_width_22_0_p),
        cmocka_unit_test(test_ft_printf_width_22_ptr_p),
        cmocka_unit_test(test_ft_printf_width_0_1_0_p),
        cmocka_unit_test(test_ft_printf_width_0_1_ptr_p),
        cmocka_unit_test(test_ft_printf_width_neg_0_0_p),
        cmocka_unit_test(test_ft_printf_width_neg_0_ptr_p),
        cmocka_unit_test(test_ft_printf_width_neg_1_0_p),
        cmocka_unit_test(test_ft_printf_width_neg_1_ptr_p),
        cmocka_unit_test(test_ft_printf_width_neg_22_0_p),
        cmocka_unit_test(test_ft_printf_width_neg_22_ptr_p),
        cmocka_unit_test(test_ft_printf_width_0_0_d),
        cmocka_unit_test(test_ft_printf_width_0_neg_d),
        cmocka_unit_test(test_ft_printf_width_0_INT_MAX_d),
        cmocka_unit_test(test_ft_printf_width_0_INT_MIN_d),
        cmocka_unit_test(test_ft_printf_width_1_0_d),
        cmocka_unit_test(test_ft_printf_width_1_neg_d),
        cmocka_unit_test(test_ft_printf_width_1_INT_MAX_d),
        cmocka_unit_test(test_ft_printf_width_1_INT_MIN_d),
        cmocka_unit_test(test_ft_printf_width_22_0_d),
        cmocka_unit_test(test_ft_printf_width_22_neg_d),
        cmocka_unit_test(test_ft_printf_width_22_INT_MAX_d),
        cmocka_unit_test(test_ft_printf_width_22_INT_MIN_d),
        cmocka_unit_test(test_ft_printf_width_0_1_0_d),
        cmocka_unit_test(test_ft_printf_width_0_1_neg_d),
        cmocka_unit_test(test_ft_printf_width_0_1_INT_MAX_d),
        cmocka_unit_test(test_ft_printf_width_0_1_INT_MIN_d),
        cmocka_unit_test(test_ft_printf_width_0_22_0_d),
        cmocka_unit_test(test_ft_printf_width_0_22_neg_d),
        cmocka_unit_test(test_ft_printf_width_0_22_INT_MAX_d),
        cmocka_unit_test(test_ft_printf_width_0_22_INT_MIN_d),
        cmocka_unit_test(test_ft_printf_width_neg_0_0_d),
        cmocka_unit_test(test_ft_printf_width_neg_0_neg_d),
        cmocka_unit_test(test_ft_printf_width_neg_0_INT_MAX_d),
        cmocka_unit_test(test_ft_printf_width_neg_0_INT_MIN_d),
        cmocka_unit_test(test_ft_printf_width_neg_1_0_d),
        cmocka_unit_test(test_ft_printf_width_neg_1_neg_d),
        cmocka_unit_test(test_ft_printf_width_neg_1_INT_MAX_d),
        cmocka_unit_test(test_ft_printf_width_neg_1_INT_MIN_d),
        cmocka_unit_test(test_ft_printf_width_neg_22_0_d),
        cmocka_unit_test(test_ft_printf_width_neg_22_neg_d),
        cmocka_unit_test(test_ft_printf_width_neg_22_INT_MAX_d),
        cmocka_unit_test(test_ft_printf_width_neg_22_INT_MIN_d),
    };
    cmocka_run_group_tests(ft_printf_width_tests, NULL, NULL);
}
