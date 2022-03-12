/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:35:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 15:35:49 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_is_format_flag(const char c)
{
	if (c == '#'
		|| c == ' '
		|| c == '+')
		return (1);
	return (0);
}

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.alternate_form = 0;
	flags.left_blank = 0;
	flags.plus_sign = 0;
	return (flags);
}

t_flags	ft_get_flags(const char **f)
{
	t_flags	flags;

	flags = init_flags();
	(*f)++;
	while (ft_is_format_flag(**f))
	{
		if (**f == '#')
			flags.alternate_form = 1;
		else if (**f == ' ')
			flags.left_blank = 1;
		else if (**f == '+')
			flags.plus_sign = 1;
		(*f)++;
	}
	return (flags);
}
