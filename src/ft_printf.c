/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 16:38:58 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

int	ft_print_conversion(const char **f, va_list ap, t_flags flags)
{
	int	i;

	i = 0;
	if (**f == 'c')
		i = ft_print_char(f, va_arg(ap, int), flags);
	else if (**f == 's')
		i = ft_print_string(f, va_arg(ap, char *), flags);
	else if (**f == 'p')
		i = ft_print_pointer(f, va_arg(ap, void *), flags);
	else if (**f == 'd' || **f == 'i')
		i = ft_print_decimal(f, va_arg(ap, int), flags);
	else if (**f == 'u')
		i = ft_print_unsigned(f, va_arg(ap, unsigned int), flags);
	else if (**f == 'x')
		i = ft_print_hex_lower(f, va_arg(ap, unsigned), flags);
	else if (**f == 'X')
		i = ft_print_hex_upper(f, va_arg(ap, unsigned), flags);
	else
		i = ft_print_char(f, **f, flags);
	return (i);
}

int	ft_vprintf(const char *f, va_list ap)
{
	int		i;
	t_flags	flags;

	i = 0;
	if (f)
	{
		while (*f)
		{
			if (*f == '%')
			{
				flags = ft_get_flags(&f);
				i += ft_print_conversion(&f, ap, flags);
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
