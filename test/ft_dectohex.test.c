#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdlib.h>
#include <limits.h>
#include <ft_printf.h>

static void test_ft_dectohex_0(void **state) {
	char	*hex = ft_dectohex(0);
    (void) state;
    assert_string_equal(hex, "0");
	free(hex);
}
static void test_ft_dectohex_1(void **state) {
	char	*hex = ft_dectohex(1);
    (void) state;
    assert_string_equal(hex, "1");
	free(hex);
}
static void test_ft_dectohex_123(void **state) {
	char	*hex = ft_dectohex(123);
    (void) state;
    assert_string_equal(hex, "7b");
	free(hex);
}
static void test_ft_dectohex_31535(void **state) {
	char	*hex = ft_dectohex(31535);
    (void) state;
    assert_string_equal(hex, "7b2f");
	free(hex);
}
static void test_ft_dectohex_315352345(void **state) {
	char	*hex = ft_dectohex(315352345);
    (void) state;
    assert_string_equal(hex, "12cbe519");
	free(hex);
}
static void test_ft_dectohex_ulong_max(void **state) {
    (void) state;
	char	*hex = ft_dectohex(ULONG_MAX);
    assert_string_equal(hex, "ffffffffffffffff");
	free(hex);
}

int main(void) {
    const struct CMUnitTest ft_dectohex[] = {
        cmocka_unit_test(test_ft_dectohex_0),
        cmocka_unit_test(test_ft_dectohex_1),
        cmocka_unit_test(test_ft_dectohex_123),
        cmocka_unit_test(test_ft_dectohex_31535),
        cmocka_unit_test(test_ft_dectohex_315352345),
        cmocka_unit_test(test_ft_dectohex_ulong_max),
    };
    return cmocka_run_group_tests(ft_dectohex, NULL, NULL);
}
