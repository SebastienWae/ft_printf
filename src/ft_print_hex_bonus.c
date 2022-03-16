/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 17:44:12 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format_bonus.h>
#include <ft_flags.h>
#include <ft_utils.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_hex_lower(va_list ap, t_f_flags f_flags)
{
	char			*str;
	int				len;
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	str = ft_dectohex(u);
	len = ft_strlen(str);
	if (u == 0 && f_flags.is_precise && f_flags.dot_precision == 0)
		len = 0;
	if (u)
		len += ft_format_alternate_form(x_c_flag, f_flags);
	len += ft_format_before(x_c_flag, f_flags, len);
	if (!(u == 0 && f_flags.is_precise && f_flags.dot_precision == 0))
		ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_format_after(f_flags, len);
	free(str);
	return (len);
}

int	ft_print_hex_upper(va_list ap, t_f_flags f_flags)
{
	char			*str;
	int				len;
	int				i;
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	str = ft_dectohex(u);
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[(i)]);
		i++;
	}
	len = ft_strlen(str);
	if (u == 0 && f_flags.is_precise && f_flags.dot_precision == 0)
		len = 0;
	if (u)
		len += ft_format_alternate_form(X_c_flag, f_flags);
	len += ft_format_before(X_c_flag, f_flags, len);
	if (!(u == 0 && f_flags.is_precise && f_flags.dot_precision == 0))
		ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_format_after(f_flags, len);
	free(str);
	return (len);
}
