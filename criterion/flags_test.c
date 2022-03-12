/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:42:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 14:13:21 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <ft_printf.h>

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
