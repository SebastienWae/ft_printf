/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:47:11 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 16:07:29 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_print_unsigned(const char **f, va_list ap, t_flags flags)
{
	unsigned	u;
	int			len;
	char		*tmp;
	char		*s;

	(void)flags;
	u = va_arg(ap, unsigned);
	if (u > 2147483647)
	{
		tmp = ft_itoa(u / 10);
		len = ft_strlen(tmp);
		s = malloc(sizeof(char) * (len + 2));
		ft_strlcpy(s, tmp, len + 2);
		free(tmp);
		tmp = ft_itoa(u % 10);
		s[len] = *tmp; 
		free(tmp);
		s[len + 1] = 0;
	}
	else
		s = ft_itoa(u);
	ft_putstr_fd(s, STDOUT_FILENO);
	len = ft_strlen(s);
	free(s);
	(*f)++;
	return (len);
}

