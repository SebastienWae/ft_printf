/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 21:50:44 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char	*ft_convert_hex_lower(const char **f, va_list ap)
{
	(*f)++;
	return (ft_dectohex(va_arg(ap, unsigned)));
}

char	*ft_convert_hex_upper(const char **f, va_list ap)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_dectohex(va_arg(ap, unsigned));
	while (str[i])
	{
		str[i] = ft_toupper(str[(i)]);
		i++;
	}
	(*f)++;
	return (str);
}
