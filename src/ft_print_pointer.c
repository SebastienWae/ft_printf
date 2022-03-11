/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:10 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/11 22:50:49 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>

int	ft_print_pointer(const char **f, void *ptr, t_flags flags)
{
	char	*s;
	int		len;
	(void)flags;

	s = ft_itohex((unsigned long)(ptr));
	len = ft_strlen(s);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(s, STDOUT_FILENO);
	free(s);
	*f += len;
	return (2 + len);
}

