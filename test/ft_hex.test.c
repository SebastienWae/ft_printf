/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:42:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/11 18:24:00 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <ft_printf.h>

Test(ft_itohex, t_0_to_hex) {
	char	s[9];
    cr_expect(eq(str, ft_itohex(0, s), "0"));
}

Test(ft_itohex, t_1_to_hex) {
	char	s[9];
    cr_expect(eq(str, ft_itohex(1, s), "1"));
}

Test(ft_itohex, t_123_to_hex) {
	char	s[9];
    cr_expect(eq(str, ft_itohex(123, s), "7B"));
}

Test(ft_itohex, t_31535_to_hex) {
	char	s[9];
    cr_expect(eq(str, ft_itohex(31535, s), "7B2F"));
}

Test(ft_itohex, t_315352345_to_hex) {
	char	s[9];
    cr_expect(eq(str, ft_itohex(315352345, s), "12CBE519"));
}

Test(ft_itohex, t_4294967295_to_hex) {
	char	s[9];
    cr_expect(eq(str, ft_itohex(4294967295, s), "FFFFFFFF"));
}
