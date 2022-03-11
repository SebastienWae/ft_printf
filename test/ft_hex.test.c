/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:42:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/11 22:49:18 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <unistd.h>

#include <ft_printf.h>

Test(ft_itohex, t_0_to_hex) {
	char	*hex = ft_itohex(0);
    cr_expect(eq(str, hex, "0"));
	free(hex);
}

Test(ft_itohex, t_1_to_hex) {
	char	*hex = ft_itohex(1);
    cr_expect(eq(str, hex, "1"));
	free(hex);
}

Test(ft_itohex, t_123_to_hex) {
	char	*hex = ft_itohex(123);
    cr_expect(eq(str, hex, "7B"));
	free(hex);
}

Test(ft_itohex, t_31535_to_hex) {
	char	*hex = ft_itohex(31535);
    cr_expect(eq(str, hex, "7B2F"));
	free(hex);
}

Test(ft_itohex, t_315352345_to_hex) {
	char	*hex = ft_itohex(315352345);
    cr_expect(eq(str, hex, "12CBE519"));
	free(hex);
}

Test(ft_itohex, t_4294967295_to_hex) {
	char	*hex = ft_itohex(4294967295);
    cr_expect(eq(str, hex, "FFFFFFFF"));
	free(hex);
}
