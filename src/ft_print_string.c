/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 16:56:35 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_print_string(const char **f, char *s, t_flags flags)
{
	int	i;

	(void)flags;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar_fd(s[i], STDOUT_FILENO);
		i++;
	}
	(*f)++;
	return (i);
}
