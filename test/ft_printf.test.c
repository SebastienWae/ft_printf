/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:42:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/11 22:51:09 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>

#include <stdarg.h>

#include <ft_printf.h>

int	mock_printf(const char *f, ...)
{
	int		i;
	va_list	va_ptr;
	t_flags	flags;

    va_start(va_ptr, f);
	flags = init_flags();
    i = ft_print_conversion(&f, va_ptr, flags);
    va_end(va_ptr);
    return (i);
}

void    create_va(va_list *va_ptr, ...)
{
    va_start(*va_ptr, va_ptr);
}

void redirect_all_std(void)
{
    cr_redirect_stdout();
  //    cr_redirect_stderr();
}

Test(ft_get_flags, no_flags) {
    t_flags     flags;
    const char  *s = "%s";
    
    flags = ft_get_flags(&s);
    cr_expect(ne(i32, flags.alternate_form, 1));
    cr_expect(ne(i32, flags.left_blank, 1));
    cr_expect(ne(i32, flags.plus_sign, 1));
}

Test(ft_get_flags, alternate_form_flag) {
    t_flags     flags;
    const char  *s = "%#";
    
    flags = ft_get_flags(&s);
    cr_expect(eq(i32, flags.alternate_form, 1));
    cr_expect(ne(i32, flags.left_blank, 1));
    cr_expect(ne(i32, flags.plus_sign, 1));
}

Test(ft_get_flags, left_blank_flag) {
    t_flags     flags;
    const char  *s = "% d";
    
    flags = ft_get_flags(&s);
    cr_expect(ne(i32, flags.alternate_form, 1));
    cr_expect(eq(i32, flags.left_blank, 1));
    cr_expect(ne(i32, flags.plus_sign, 1));
}

Test(ft_get_flags, plus_sign_flag) {
    t_flags     flags;
    const char  *s = "%+d";
    
    flags = ft_get_flags(&s);
    cr_expect(ne(i32, flags.alternate_form, 1));
    cr_expect(ne(i32, flags.left_blank, 1));
    cr_expect(eq(i32, flags.plus_sign, 1));
}

Test(ft_get_flags, multi_flags) {
    t_flags     flags;
    const char  *s = "%+ #+ #d#";
    
    flags = ft_get_flags(&s);
    cr_expect(eq(i32, flags.alternate_form, 1));
    cr_expect(eq(i32, flags.left_blank, 1));
    cr_expect(eq(i32, flags.plus_sign, 1));
}

//Test(ft_print_conversion, print_c, .init = redirect_all_std) {
    //cr_expect(eq(i32, mock_printf("%c", 'c'), 1));
    //cr_assert_stdout_eq_str("c");
//}

//Test(ft_print_conversion, print_string, .init = redirect_all_std) {
    //cr_expect(eq(i32, mock_printf("%s", "string"), 6));
    //cr_assert_stdout_eq_str("string");
//}

Test(ft_print_conversion, print_pointer, .init = redirect_all_std) {
    char    *ptr;

    ptr = 0;
    cr_expect(eq(i32, mock_printf("%p", ptr), 3));
    cr_assert_stdout_eq_str("0x0");
}
