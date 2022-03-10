/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:51:04 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/10 17:33:02 by swaegene         ###   ########.fr       */
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
t_flags	ft_get_flags(const char **f, int *i);
int		ft_is_format_flag(const char c);

#endif
