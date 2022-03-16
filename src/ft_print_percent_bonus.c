/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 12:43:25 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format_bonus.h>
#include <ft_flags.h>
#include <libft.h>
#include <stdarg.h>

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
