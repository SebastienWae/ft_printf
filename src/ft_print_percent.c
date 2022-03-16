/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 17:44:46 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_percent(va_list ap, t_f_flags flags)
{
	int	len;

	(void)ap;
	(void)flags;
	len = 1;
	ft_putchar_fd('%', STDOUT_FILENO);
	return (len);
	return (1);
}
