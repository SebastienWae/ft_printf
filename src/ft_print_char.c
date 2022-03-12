/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:41 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 13:21:10 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_print_char(const char **f, int c, t_flags flags)
{
	(void)flags;
	ft_putchar_fd(c, STDOUT_FILENO);
	(*f)++;
	return (1);
}
