/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 23:25:29 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*ft_convert_char(const char **f, va_list ap)
{
	char	*str;
	char	c;

	c = (unsigned char)va_arg(ap, int);
	str = ft_calloc(2, sizeof(char));
	str[0] = c;
	if (!c)
		ft_putchar_fd(0, STDOUT_FILENO);
	(*f)++;
	return (str);

}
