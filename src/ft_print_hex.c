/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 14:04:14 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_print_hex_lower(const char **f, unsigned u, t_flags flags)
{
	int		i;
	int 	len;
	char	*s;

	(void)flags;
	s = ft_dectohex(u);
	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[(i)]);
		i++;
	}
	ft_putstr_fd(s, STDOUT_FILENO);
	len = ft_strlen(s);
	*f += len;
	return (len);
}

int	ft_print_hex_upper(const char **f, unsigned u, t_flags flags)
{
	int 	len;
	char	*s;

	(void)flags;
	s = ft_dectohex(u);
	ft_putstr_fd(s, STDOUT_FILENO);
	len = ft_strlen(s);
	*f += len;
	return (len);
}
