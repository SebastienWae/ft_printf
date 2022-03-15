/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:47:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 22:41:17 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char	*ft_convert_unsigned(const char **f, va_list ap)
{
	unsigned	u;
	char		*tmp;
	char		*tmp2;
	char		*str;

	u = va_arg(ap, unsigned);
	if (u > 2147483647)
	{
		tmp = ft_itoa(u / 10);
		tmp2 = ft_itoa(u % 10);
		str = ft_strappend(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
		str = ft_itoa(u);
	(*f)++;
	return (str);
}

