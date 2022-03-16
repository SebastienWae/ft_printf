/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:51:04 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 11:13:29 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define C_FLAGS "cspdiuxX%"
# define C_FLAGS_LEN (sizeof(C_FLAGS) - 1)
# define F_FLAGS "-0.# +"
# define F_FLAGS_LEN (sizeof(F_FLAGS) - 1)

enum		e_c_flags
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

enum		e_f_flags
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

int				ft_printf(const char *f, ...);

int				ft_hash_flag(char *k, char f);
t_f_flags		ft_get_f_flags(const char **f);
unsigned int	ft_get_f_flag_arg(const char **f);

int				ft_print_char(va_list a,t_f_flags f);
int				ft_print_string(va_list a,t_f_flags f);
int				ft_print_pointer(va_list a,t_f_flags f);
int				ft_print_decimal(va_list a,t_f_flags f);
int				ft_print_int(va_list a,t_f_flags f);
int				ft_print_unsigned(va_list a,t_f_flags f);
int				ft_print_hex_lower(va_list a,t_f_flags f);
int				ft_print_hex_upper(va_list a,t_f_flags f);
int				ft_print_percent(va_list a,t_f_flags f);

void			ft_parse_alternate_form(const char **f,t_f_flags *ff);
void			ft_parse_left_blank(const char **f,t_f_flags *ff);
void			ft_parse_plus_sign(const char **f,t_f_flags *ff);
void			ft_parse_zero_padding(const char **f,t_f_flags *ff);
void			ft_parse_minus_padding(const char **f,t_f_flags *ff);
void			ft_parse_dot_precision(const char **f,t_f_flags *ff);

int				ft_format_before(enum e_c_flags c_flag, t_f_flags f_flags, unsigned int size);
int				ft_format_after(t_f_flags f_flags, unsigned int size);

char			*ft_dectobase(unsigned long d, char *b, unsigned int bs);
char			*ft_dectohex(unsigned long n);

char			*ft_strappend(char *src, char *appendix);
char			*ft_strprepend(char *src, char *prefix);

#endif
