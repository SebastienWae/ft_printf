/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:47:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 10:17:10 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_print_unsigned(va_list ap,t_f_flags flags)
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
	len += ft_format_before(s_c_flag, flags, len);
	ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_format_after(flags, len);
	free(str);
	return (len);
}

