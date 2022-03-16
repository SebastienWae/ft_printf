/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:47:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 16:05:29 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <ft_format_bonus.h>
#include <ft_utils.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_unsigned(va_list ap,t_f_flags f_flags)
{
	unsigned	u;
	char		*tmp;
	char		*tmp2;
	char		*str;
	int			len;

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
	len = ft_strlen(str);
	if (u == 0 && f_flags.is_precise && f_flags.dot_precision == 0)
		len = 0;
	len += ft_format_before(u_c_flag, f_flags, len);
	if (!(u == 0 && f_flags.is_precise && f_flags.dot_precision == 0))
		ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_format_after(f_flags, len);
	free(str);
	return (len);
}

