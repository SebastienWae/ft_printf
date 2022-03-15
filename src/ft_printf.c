/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 18:29:11 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

int	ft_vprintf(const char *f, va_list ap)
{
	int						i;
	t_flags					flags;
	static t_print_convert	print_convert[] = {ft_print_char, ft_print_string,
		ft_print_pointer, ft_print_decimal, ft_print_decimal, ft_print_unsigned,
		ft_print_hex_lower, ft_print_hex_upper, ft_print_percentage};

	i = 0;
	if (f)
	{
		while (*f)
		{
			if (*f == '%' && f[1] && ft_strrchr(C_FLAGS, f[1]))
			{
				flags = ft_get_flags(&f);
				i += print_convert[ft_hash_flag(C_FLAGS, *f)](&f, ap, flags);
			}
			else
			{
				ft_putchar_fd(*f, STDOUT_FILENO);
				f++;
				i++;
			}
		}
	}
	return (i);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, f);
	i = ft_vprintf(f, ap);
	va_end(ap);
	return (i);
}
