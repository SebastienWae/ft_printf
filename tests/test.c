#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <libftprintf.h>

Test(ft_printf, eq) {
    cr_assert(eq(i64, ft_printf("test"), 1));
}
Test(ft_printf, ne) {
    cr_assert(ne(i64, ft_printf("test"), 1));
}