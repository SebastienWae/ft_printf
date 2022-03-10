/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/10 18:11:51 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <ft_convert.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_is_format_flag(const char c)
{
	if (c == '#'
		|| c == ' '
		|| c == '+')
		return (1);
	return (0);
}

t_flags	ft_get_flags(const char **f, int *i)
{
	t_flags	flags;

	flags.alternate_form = 0;
	flags.left_blank = 0;
	flags.plus_sign = 0;
	(*f)++;
	(*i)++;
	while (ft_is_format_flag(**f))
	{
		if (**f == '#')
			flags.alternate_form = 1;
		else if (**f == ' ')
			flags.left_blank = 1;
		else if (**f == '+')
			flags.plus_sign = 1;
		(*f)++;
		(*i)++;
	}
	return (flags);
}

//%c Prints a single character.
//%s Prints a string (as defined by the common C convention).
//%p The void * pointer argument has to be printed in hexadecimal format.
//%d Prints a decimal (base 10) number.
//%i Prints an integer in base 10.
//%u Prints an unsigned decimal (base 10) number.
//%x Prints a number in hexadecimal (base 16) lowercase format.
//%X Prints a number in hexadecimal (base 16) uppercase format.
//%% Prints a percent sign

int	ft_print_conversion(const char **f, va_list va_ptr, t_flags flags)
{
	int	i;

	i = 0;
	(*f)++;
	i++;
	if (**f == 'c')
	{
		ft_putchar_fd((char)va_arg(va_ptr, int), STDOUT_FILENO);
		(*f)++;
		i++;
	}
	else if (**f == 's')
		i = ft_convert_s(va_arg(va_ptr, char *));
	else
	{
		ft_putchar_fd(**f, STDOUT_FILENO);
		(*f)++;
		i++;
	}
	(void)flags;
	return (i);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	va_list	va_ptr;
	t_flags	flags;

	i = 0;
	if (f)
	{
		va_start(va_ptr, f);
		while (*f)
		{
			if (*f == '%')
			{
				flags = ft_get_flags(&f, &i);
				i += ft_print_conversion(&f, va_ptr, flags);
			}
			else
			{
				ft_putchar_fd(*f, STDOUT_FILENO);
				f++;
				i++;
			}
		}
		va_end(va_ptr);
	}
	return (i);
}
