/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:10 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/11 18:22:54 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>

int	ft_print_pointer(const char **f, void *ptr, t_flags flags)
{
	char	s[9];
	int		len;
	(void)flags;

	ft_itohex((unsigned long)(ptr), (char *)&s);
	len = ft_strlen(s);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(s, STDOUT_FILENO);
	*f += len;
	return (3 + len);
}

