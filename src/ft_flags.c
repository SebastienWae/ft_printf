/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:35:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 16:48:26 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <ft_parse.h>
#include <libft.h>

int	ft_hash_flag(char *key, char flag)
{
	return (ft_strchr(key, flag) - key);
}

unsigned int	ft_get_f_flag_arg(const char **f)
{
	unsigned long long	arg;

	arg = 0;
	while (ft_isdigit(**f))
		arg = (arg * 10) + (*(*f)++ - '0');
	return (arg);
}

static t_f_flags	ft_init_f_flags(void)
{
	t_f_flags	f_flags;

	f_flags.alternate_form = 0;
	f_flags.left_blank = 0;
	f_flags.plus_sign = 0;
	f_flags.zero_padding = 0;
	f_flags.minus_padding = 0;
	f_flags.is_precise = 0;
	f_flags.dot_precision = 0;
	f_flags.field_width = 0;
	return (f_flags);
}

static void	init_parse_f_flags(t_parse_f_flag *arr)
{

	arr[minus_f_flag] = ft_parse_minus_padding;
	arr[zero_f_flag] = ft_parse_zero_padding;
	arr[dot_f_flag] = ft_parse_dot_precision;
	arr[hash_f_flag] = 	ft_parse_alternate_form;
	arr[space_f_flag] = ft_parse_left_blank;
	arr[plus_f_flag] = ft_parse_plus_sign;

}

t_f_flags	ft_get_f_flags(const char **f)
{
	t_f_flags		f_flags;
	t_parse_f_flag	parse_f_flags[F_FLAGS_LEN];

	f_flags = ft_init_f_flags();
	init_parse_f_flags(parse_f_flags);
	while (ft_strchr(F_FLAGS, **f))
		parse_f_flags[ft_hash_flag(F_FLAGS, **f)](f, &f_flags);
	while (ft_strchr(F_FLAGS, **f) || ft_isdigit(**f))
	{
		if (ft_isdigit(**f))
			f_flags.field_width = ft_get_f_flag_arg(f);
		else
			parse_f_flags[ft_hash_flag(F_FLAGS, **f)](f, &f_flags);
	}
	return (f_flags);
}
