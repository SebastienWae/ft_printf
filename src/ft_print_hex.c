/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 12:56:14 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <ft_utils.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_hex_lower(va_list ap,t_f_flags flags)
{
	char	*str;
	int		len;

	(void)flags;
	str = ft_dectohex(va_arg(ap, unsigned));
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (len);
}

int	ft_print_hex_upper(va_list ap,t_f_flags flags)
{
	char	*str;
	int		len;
	int		i;

	(void)flags;
	str = ft_dectohex(va_arg(ap, unsigned));
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[(i)]);
		i++;
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (len);
}
