/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 10:08:25 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_print_char(va_list ap,t_f_flags flags)
{
	int	len;

	len = 1;
	len += ft_format_before(c_c_flag, flags, len);
	ft_putchar_fd((unsigned char)va_arg(ap, int), STDOUT_FILENO);
	len += ft_format_after(flags, len);
	return (len);

}
