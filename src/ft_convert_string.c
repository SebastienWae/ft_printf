/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 22:35:59 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*ft_convert_string(const char **f, va_list ap)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	(*f)++;
	return (str);
}
