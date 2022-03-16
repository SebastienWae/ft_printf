/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 15:09:09 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format_bonus.h>
#include <ft_flags.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_string(va_list ap,t_f_flags f_flags)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (f_flags.is_precise)
		str = ft_substr(str, 0, f_flags.dot_precision);
	len = ft_strlen(str);
	len += ft_format_before(s_c_flag, f_flags, len);
	ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_format_after(f_flags, len);
	if (f_flags.is_precise)
		free(str);
	return (len);
}
