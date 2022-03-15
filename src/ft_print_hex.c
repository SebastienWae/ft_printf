/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 17:01:19 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_print_hex_lower(const char **f, va_list ap, t_flags flags)
{
	int		len;
	char	*s;

	(void)flags;
	s = ft_dectohex(va_arg(ap, unsigned));
	ft_putstr_fd(s, STDOUT_FILENO);
	len = ft_strlen(s);
	free(s);
	(*f)++;
	return (len);
}

int	ft_print_hex_upper(const char **f, va_list ap, t_flags flags)
{
	int		i;
	int		len;
	char	*s;

	(void)flags;
	s = ft_dectohex(va_arg(ap, unsigned));
	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[(i)]);
		i++;
	}
	ft_putstr_fd(s, STDOUT_FILENO);
	len = ft_strlen(s);
	free(s);
	(*f)++;
	return (len);
}
