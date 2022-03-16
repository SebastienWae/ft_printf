/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/16 11:13:18 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

static void	init_print_convert(t_print_convert *arr)
{
	arr[c_c_flag] = ft_print_char;
	arr[s_c_flag] = ft_print_string;
	arr[p_c_flag] = ft_print_pointer;
	arr[d_c_flag] = ft_print_decimal;
	arr[i_c_flag] = ft_print_int;
	arr[u_c_flag] = ft_print_unsigned;
	arr[x_c_flag] = ft_print_hex_lower;
	arr[X_c_flag] = ft_print_hex_upper;
	arr[percent_c_flag] = ft_print_percent;
}

static int	ft_print_convert(const char **f, va_list ap)
{
	int				len;
	t_f_flags		f_flags;
	t_print_convert	print_convert[C_FLAGS_LEN];

	len = 0;
	f_flags = ft_get_f_flags(f);
	init_print_convert(print_convert);
	if (ft_strchr(C_FLAGS, **f))
		len = print_convert[ft_hash_flag(C_FLAGS, **f)](ap, f_flags);
	(*f)++;
	return (len);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, f);
	i = 0;
	if (f)
	{
		while (*f)
		{
			if (*f == '%' && f[1] && (ft_strrchr(C_FLAGS, f[1])
				|| ft_strchr(F_FLAGS, f[1]) || ft_isdigit(f[1])))
			{
				f++;
				i += ft_print_convert(&f, ap);
			}
			else
			{
				ft_putchar_fd(*f, STDOUT_FILENO);
				f++;
				i++;
			}
		}
	}
	va_end(ap);
	return (i);
}
