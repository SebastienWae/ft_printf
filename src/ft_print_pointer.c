/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:06:10 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 16:47:32 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_print_pointer(const char **f, void *ptr, t_flags flags)
{
	char	*s;
	int		len;

	(void)flags;
	s = ft_dectohex((unsigned long)(ptr));
	len = ft_strlen(s);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(s, STDOUT_FILENO);
	free(s);
	(*f)++;
	return (2 + len);
}
