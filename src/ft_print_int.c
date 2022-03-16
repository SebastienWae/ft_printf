/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:22:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 17:44:33 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_int(va_list ap, t_f_flags flags)
{
	char	*str;
	int		len;

	(void)flags;
	str = ft_itoa(va_arg(ap, int));
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (len);
}
