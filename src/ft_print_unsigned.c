/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:47:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 17:54:43 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <ft_utils.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_unsigned(va_list ap, t_f_flags flags)
{
	unsigned int	u;
	char			*str;
	int				len;

	(void)flags;
	u = va_arg(ap, unsigned);
	str = ft_utoa(u);
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (len);
}
