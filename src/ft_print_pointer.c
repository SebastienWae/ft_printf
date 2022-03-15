/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:10 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 16:06:00 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_print_pointer(const char **f, va_list ap, t_flags flags)
{
	char	*s;
	int		len;

	(void)flags;
	s = ft_dectohex((unsigned long)(va_arg(ap, void *)));
	len = ft_strlen(s);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(s, STDOUT_FILENO);
	free(s);
	(*f)++;
	return (2 + len);
}
