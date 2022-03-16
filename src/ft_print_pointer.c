/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:10 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 10:16:39 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_print_pointer(va_list ap,t_f_flags flags)
{
	char	*str;
	int		len;

	str = ft_dectohex((unsigned long)(va_arg(ap, void *)));
	len = ft_strlen(str) + 2;
	len += ft_format_before(p_c_flag, flags, len);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_format_after(flags, len);
	free(str);
	return (len);
}
