/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:22:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 13:36:58 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_print_decimal(const char **f, int dec, t_flags flags)
{
	char	*s;

	(void)flags;
	s = ft_itoa(dec);
	ft_putstr_fd(s, STDOUT_FILENO);
	while (ft_isdigit(**f))
		(*f)++;
	return (ft_strlen(s));
}
