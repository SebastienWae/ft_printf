/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:22:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 10:16:25 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_print_decimal(va_list ap,t_f_flags flags)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(ap, int));
	len = ft_strlen(str);
	len += ft_format_before(d_c_flag, flags, len);
	ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_format_after(flags, len);
	free(str);
	return (len);
}
