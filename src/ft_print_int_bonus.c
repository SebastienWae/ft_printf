/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:22:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 15:56:54 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format_bonus.h>
#include <ft_flags.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_int(va_list ap,t_f_flags f_flags)
{
	char	*str;
	int		len;
	int		dec;

	dec = va_arg(ap, int);
	str = ft_itoa(dec);
	len = ft_strlen(str);
	if (dec == 0 && f_flags.is_precise && f_flags.dot_precision == 0)
		len = 0;
	if (dec >= 0)
		len += ft_format_insert_char(f_flags);
	if (dec < 0)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		len += ft_format_before(i_c_flag, f_flags, len - 1);
	}
	else
		len += ft_format_before(i_c_flag, f_flags, len);
	if (dec < 0)
		ft_putstr_fd((str + 1), STDOUT_FILENO);
	else if (!(dec == 0 && f_flags.is_precise && f_flags.dot_precision == 0))
		ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_format_after(f_flags, len);
	free(str);
	return (len);
}
