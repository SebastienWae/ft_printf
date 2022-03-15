/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:22:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 16:03:45 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_print_decimal(const char **f, va_list ap, t_flags flags)
{
	char	*s;
	int		len;

	(void)flags;
	s = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(s, STDOUT_FILENO);
	(*f)++;
	len = ft_strlen(s);
	free(s);
	return (len);
}
