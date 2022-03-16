/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 12:36:29 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_char(va_list ap,t_f_flags flags)
{
	int	len;

	(void)flags;
	len = 1;
	ft_putchar_fd((unsigned char)va_arg(ap, int), STDOUT_FILENO);
	return (len);

}
