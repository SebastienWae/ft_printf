/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:42:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 13:04:18 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <unistd.h>

#include <ft_printf.h>

Test(ft_dectohex, t_0_to_hex) {
	char	*hex = ft_dectohex(0);
    cr_expect(eq(str, hex, "0"));
	free(hex);
}

Test(ft_dectohex, t_1_to_hex) {
	char	*hex = ft_dectohex(1);
    cr_expect(eq(str, hex, "1"));
	free(hex);
}

Test(ft_dectohex, t_123_to_hex) {
	char	*hex = ft_dectohex(123);
    cr_expect(eq(str, hex, "7B"));
	free(hex);
}

Test(ft_dectohex, t_31535_to_hex) {
	char	*hex = ft_dectohex(31535);
    cr_expect(eq(str, hex, "7B2F"));
	free(hex);
}

Test(ft_dectohex, t_315352345_to_hex) {
	char	*hex = ft_dectohex(315352345);
    cr_expect(eq(str, hex, "12CBE519"));
	free(hex);
}

Test(ft_dectohex, t_4294967295_to_hex) {
	char	*hex = ft_dectohex(4294967295);
    cr_expect(eq(str, hex, "FFFFFFFF"));
	free(hex);
}
