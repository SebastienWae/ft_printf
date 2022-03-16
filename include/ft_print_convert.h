/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_convert.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:23:38 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 12:24:30 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_CONVERT_H
# define FT_PRINT_CONVERT_H

# include <stdarg.h>
# include <ft_flags.h>

int	ft_print_char(va_list a,t_f_flags f);
int	ft_print_string(va_list a,t_f_flags f);
int	ft_print_pointer(va_list a,t_f_flags f);
int	ft_print_decimal(va_list a,t_f_flags f);
int	ft_print_int(va_list a,t_f_flags f);
int	ft_print_unsigned(va_list a,t_f_flags f);
int	ft_print_hex_lower(va_list a,t_f_flags f);
int	ft_print_hex_upper(va_list a,t_f_flags f);
int	ft_print_percent(va_list a,t_f_flags f);

#endif
