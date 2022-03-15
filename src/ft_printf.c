/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/15 23:28:21 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

static char	*ft_format(char *str, char c_flag, t_flags flags)
{
	char	*tmp;

	if (c_flag == 'i' || c_flag == 'd')
	{
		if (flags.plus_sign)
			ft_putchar_fd('+', STDOUT_FILENO);
		else if (flags.left_blank)
            ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (c_flag == 'x' || c_flag == 'X')
	{
		if (flags.alternate_form)
			ft_putstr_fd("0x", STDOUT_FILENO);
	}
	if (c_flag == 'd' || c_flag == 'i' || c_flag == 'o' || c_flag == 'u' || c_flag == 'x' || c_flag == 'X')
	{
		while (ft_strlen(str) < flags.dot_precision)
		{
			tmp = str;	
			str = ft_strprepend(str, "0");
			free(tmp);
		}
	}
	while (ft_strlen(str) < flags.field_width)
	{
		tmp = str;	
		if (flags.minus_padding)
		{
			str = ft_strappend(str, " ");
		}
		else
		{
			if (flags.zero_padding && !flags.is_precise)
			{
				str = ft_strprepend(str, "0");
			}
			else
				str = ft_strprepend(str, " ");
		}
		free(tmp);
	}
	return (str);
}

static void	init_convert_to_str(t_convert_to_str *arr)
{
	arr[0] = ft_convert_char;
	arr[1] = ft_convert_string;
	arr[2] = ft_convert_pointer;
	arr[3] = ft_convert_decimal;
	arr[4] = ft_convert_decimal;
	arr[5] = ft_convert_unsigned;
	arr[6] = ft_convert_hex_lower;
	arr[7] = ft_convert_hex_upper;
	arr[8] = ft_convert_percent;
}

static int	ft_print_convert(const char **f, va_list ap)
{
	char				*str;
	char				c_flag;
	t_flags				flags;
	int					len;
	t_convert_to_str	convert_to_str[9];

	init_convert_to_str(convert_to_str);
	flags = ft_init_flags();
	len = 0;
	if (!ft_strchr(C_FLAGS, **f))
		flags = ft_get_flags(f);
	if (ft_strchr(C_FLAGS, **f))
	{
		c_flag = **f;
		str = convert_to_str[ft_hash_flag(C_FLAGS, c_flag)](f, ap);
		if (!str[0])
		{
			ft_putchar_fd(0, STDOUT_FILENO);
			len = 1;
		}
	}
	else
	{
		c_flag = 0;
		str = ft_calloc(1, sizeof(char));
	}
	str = ft_format(str, c_flag,  flags);
	ft_putstr_fd(str, STDOUT_FILENO);
	len += ft_strlen(str);
	free(str);
	return (len);
}

int	ft_vprintf(const char *f, va_list ap)
{
	int						i;

	i = 0;
	if (f)
	{
		while (*f)
		{
			if (*f == '%' && f[1]
				&& (ft_strrchr(C_FLAGS, f[1])
				|| ft_strchr(F_FLAGS, f[1])
				|| ft_isdigit(f[1])))
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
