/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:47:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 13:47:41 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_print_unsigned(const char **f, unsigned u, t_flags flags)
{
	char	*s;

	(void)flags;
	s = ft_itoa(u);
	ft_putstr_fd(s, STDOUT_FILENO);
	while (ft_isdigit(**f))
		(*f)++;
	return (ft_strlen(s));
}

