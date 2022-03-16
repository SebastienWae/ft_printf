/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 10:16:36 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_print_percent(va_list ap,t_f_flags flags)
{
	int	len;

	(void)ap;
	len = 1;
	len += ft_format_before(percent_c_flag, flags, len);
	ft_putchar_fd('%', STDOUT_FILENO);
	len += ft_format_after(flags, len);
	return (len);
	return (1);
}
