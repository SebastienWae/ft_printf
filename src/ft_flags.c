/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:35:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 22:18:24 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_hash_flag(char *key, char flag)
{
	return (ft_strchr(key, flag) - key);
}

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.alternate_form = 0;
	flags.left_blank = 0;
	flags.plus_sign = 0;
	flags.zero_padding = 0;
	flags.minus_padding = 0;
	flags.is_precise = 0;
	flags.dot_precision = 0;
	flags.field_width = 0;
	return (flags);
}

unsigned int	ft_get_flag_arg(const char **f)
{
	unsigned long long	arg;

	arg = 0;
	while (ft_isdigit(**f))
		arg = (arg * 10) + (*(*f)++ - '0');
	return (arg);
}

t_flags	ft_get_flags(const char **f)
{
	t_flags				flags;
	static t_parse_flag	parse_flag[] = {ft_parse_alternate_form,
		ft_parse_left_blank, ft_parse_plus_sign, ft_parse_zero_padding,
		ft_parse_minus_padding, ft_parse_dot_precision};

	flags = ft_init_flags();
	while (ft_strchr(F_FLAGS, **f) || ft_isdigit(**f))
	{
		if (ft_isdigit(**f))
			flags.field_width = ft_get_flag_arg(f);
		else
			parse_flag[ft_hash_flag(F_FLAGS, **f)](f, &flags);
	}
	return (flags);
}
