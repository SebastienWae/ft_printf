/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:42:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/10 18:12:04 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdarg.h>

#include <ft_printf.h>

void    create_va(va_list *va_ptr, ...)
{
    va_start(*va_ptr, va_ptr);
}

Test(ft_get_flags, no_flags) {
    int         i = 0;
    t_flags     flags;
    const char  *s = "%s";
    
    flags = ft_get_flags(&s, &i);
    cr_expect(ne(i32, flags.alternate_form, 1));
    cr_expect(ne(i32, flags.left_blank, 1));
    cr_expect(ne(i32, flags.plus_sign, 1));
    cr_expect(eq(i32, i, 1));
}

Test(ft_get_flags, alternate_form_flag) {
    int         i = 0;
    t_flags     flags;
    const char  *s = "%#";
    
    flags = ft_get_flags(&s, &i);
    cr_expect(eq(i32, flags.alternate_form, 1));
    cr_expect(ne(i32, flags.left_blank, 1));
    cr_expect(ne(i32, flags.plus_sign, 1));
    cr_expect(eq(i32, i, 2));
}

Test(ft_get_flags, left_blank_flag) {
    int         i = 0;
    t_flags     flags;
    const char  *s = "% d";
    
    flags = ft_get_flags(&s, &i);
    cr_expect(ne(i32, flags.alternate_form, 1));
    cr_expect(eq(i32, flags.left_blank, 1));
    cr_expect(ne(i32, flags.plus_sign, 1));
    cr_expect(eq(i32, i, 2));
}

Test(ft_get_flags, plus_sign_flag) {
    int         i = 0;
    t_flags     flags;
    const char  *s = "%+d";
    
    flags = ft_get_flags(&s, &i);
    cr_expect(ne(i32, flags.alternate_form, 1));
    cr_expect(ne(i32, flags.left_blank, 1));
    cr_expect(eq(i32, flags.plus_sign, 1));
    cr_expect(eq(i32, i, 2));
}

Test(ft_get_flags, multi_flags) {
    int         i = 0;
    t_flags     flags;
    const char  *s = "%+ #+ #d#";
    
    flags = ft_get_flags(&s, &i);
    cr_expect(eq(i32, flags.alternate_form, 1));
    cr_expect(eq(i32, flags.left_blank, 1));
    cr_expect(eq(i32, flags.plus_sign, 1));
    cr_expect(eq(i32, i, 7));
}

Test(ft_print_conversion, print_c) {
    t_flags     flags;
    va_list     va_ptr;
    const char  *s = "%c";

    flags.alternate_form = 0;
    flags.left_blank = 0;
    flags.plus_sign = 0;
    create_va(&va_ptr, 'c');
    cr_expect(eq(i32, ft_print_conversion(&s, va_ptr, flags), 2));
}
