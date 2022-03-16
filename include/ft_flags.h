/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:19:45 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 17:56:06 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_H
# define FT_FLAGS_H

# include <stdarg.h>

# define C_FLAGS "cspdiuxX%"
# define C_FLAGS_LEN 9
# define F_FLAGS "-0.# +"
# define F_FLAGS_LEN 6

enum	e_c_flags
{
	c_c_flag,
	s_c_flag,
	p_c_flag,
	d_c_flag,
	i_c_flag,
	u_c_flag,
	x_c_flag,
	X_c_flag,
	percent_c_flag
};

enum	e_f_flags
{
	minus_f_flag,
	zero_f_flag,
	dot_f_flag,
	hash_f_flag,
	space_f_flag,
	plus_f_flag
};

typedef struct s_f_flags
{
	unsigned int	alternate_form;
	unsigned int	left_blank;
	unsigned int	plus_sign;
	unsigned int	zero_padding;
	unsigned int	minus_padding;
	unsigned int	is_precise;
	unsigned int	dot_precision;
	unsigned int	field_width;
}	t_f_flags;

typedef int		(*t_print_convert)(va_list,t_f_flags);
typedef void	(*t_parse_f_flag)(const char **,t_f_flags *);

int				ft_hash_flag(char *k, char f);
t_f_flags		ft_get_f_flags(const char **f);
unsigned int	ft_get_f_flag_arg(const char **f);

#endif
