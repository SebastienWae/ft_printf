/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:51:04 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 22:14:01 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define C_FLAGS "cspdiuxX%"
# define F_FLAGS "-0.# +"

typedef struct s_flags
{
	unsigned int	alternate_form;
	unsigned int	left_blank;
	unsigned int	plus_sign;
	unsigned int	zero_padding;
	unsigned int	minus_padding;
	unsigned int	is_precise;
	unsigned int	dot_precision;
	unsigned int	field_width;
}	t_flags;

typedef char	*(*t_convert_to_str)(const char **, va_list);
typedef void	(*t_parse_flag)(const char **, t_flags *);

int				ft_printf(const char *f, ...);
int				ft_vprintf(const char *f, va_list a);

int				ft_hash_flag(char *k, char f);
t_flags			ft_get_flags(const char **f);
unsigned int	ft_get_flag_arg(const char **f);
t_flags			ft_init_flags(void);

char			*ft_convert_char(const char **f, va_list a);
char			*ft_convert_string(const char **f, va_list a);
char			*ft_convert_pointer(const char **f, va_list a);
char			*ft_convert_decimal(const char **f, va_list a);
char			*ft_convert_unsigned(const char **f, va_list a);
char			*ft_convert_hex_lower(const char **f, va_list a);
char			*ft_convert_hex_upper(const char **f, va_list a);
char			*ft_convert_percent(const char **f, va_list a);

void			ft_parse_alternate_form(const char **f, t_flags *fl);
void			ft_parse_left_blank(const char **f, t_flags *fl);
void			ft_parse_plus_sign(const char **f, t_flags *fl);
void			ft_parse_zero_padding(const char **f, t_flags *fl);
void			ft_parse_minus_padding(const char **f, t_flags *fl);
void			ft_parse_dot_precision(const char **f, t_flags *fl);

char			*ft_dectobase(unsigned long d, char *b, unsigned int bs);
char			*ft_dectohex(unsigned long n);

char			*ft_strappend(char *src, char *appendix);
char			*ft_strprepend(char *src, char *prefix);

#endif
