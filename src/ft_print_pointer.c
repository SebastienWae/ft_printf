/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:10 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 17:44:59 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <ft_utils.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_pointer(va_list ap, t_f_flags flags)
{
	char	*str;
	int		len;

	(void)flags;
	str = ft_dectohex((unsigned long)(va_arg(ap, void *)));
	len = ft_strlen(str) + 2;
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (len);
}
