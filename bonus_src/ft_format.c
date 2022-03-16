/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:45:58 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 10:05:48 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_format_before(enum e_c_flags c_flag, t_f_flags f_flags, unsigned int size)
{
	int	len;

	len = 0;
	if (c_flag == i_c_flag || c_flag == d_c_flag)
	{
		if (f_flags.plus_sign)
		{
			len++;
			ft_putchar_fd('+', STDOUT_FILENO);
		}
		else if (f_flags.left_blank)
		{
			len++;
			ft_putchar_fd(' ', STDOUT_FILENO);
		}
	}
	if (c_flag == x_c_flag || c_flag == X_c_flag)
	{
		if(f_flags.alternate_form)
		{
			ft_putstr_fd("0x", STDOUT_FILENO);
			len += 2;
		}
	}
	if (c_flag == d_c_flag
		|| c_flag == i_c_flag
		|| c_flag == u_c_flag
		|| c_flag == x_c_flag
		|| c_flag == X_c_flag)
	{
		while (f_flags.dot_precision > size)
		{
			ft_putchar_fd('0', STDOUT_FILENO);
			len++;
			f_flags.dot_precision--;
		}
	}
	while (f_flags.field_width > (size + len) && !f_flags.minus_padding)
	{
		if (f_flags.zero_padding && !f_flags.is_precise)
			ft_putchar_fd('0', STDOUT_FILENO);
		else
			ft_putchar_fd(' ', STDOUT_FILENO);
		len++;
	}
	return (len);
}

int	ft_format_after(t_f_flags f_flags, unsigned int size)
{
	int	len;

	len = 0;
	while (f_flags.field_width > (size + len) && f_flags.minus_padding)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		len++;
	}
	return (len);
}
