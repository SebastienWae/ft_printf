/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:10 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 22:01:04 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*ft_convert_pointer(const char **f, va_list ap)
{
	char	*tmp;
	char	*str;

	tmp = ft_dectohex((unsigned long)(va_arg(ap, void *)));
	str = ft_strprepend(tmp, "0x");
	free(tmp);
	(*f)++;
	return (str);
}
