/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:51:04 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/11 22:13:26 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_flags
{
	int	alternate_form;
	int	left_blank;
	int	plus_sign;
}	t_flags;

int		ft_printf(const char *f, ...);
int		ft_print_conversion(const char **f, va_list p, t_flags fl);
t_flags	ft_get_flags(const char **f);
t_flags	init_flags(void);
int		ft_is_format_flag(const char c);

int		ft_print_char(const char **f, int c, t_flags flags);
int		ft_print_string(const char **f , char *s, t_flags flags);
int		ft_print_pointer(const char **f, void *ptr, t_flags flags);

char	*ft_itohex(unsigned long nb);

#endif
