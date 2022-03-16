/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:45:58 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 17:42:41 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>
#include <libft.h>

int	ft_format_insert_char(t_f_flags f_flags)
{
	int	i;

	i = 0;
	if (f_flags.plus_sign)
	{
		i = 1;
		ft_putchar_fd('+', STDOUT_FILENO);
	}
	else if (f_flags.left_blank)
	{
		i = 1;
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	return (i);
}

int	ft_format_alternate_form(enum e_c_flags c_flag, t_f_flags f_flags)
{
	int	i;

	i = 0;
	if (c_flag == x_c_flag)
	{
		if (f_flags.alternate_form)
		{
			ft_putstr_fd("0x", STDOUT_FILENO);
			i += 2;
		}
	}
	if (c_flag == X_c_flag)
	{
		if (f_flags.alternate_form)
		{
			ft_putstr_fd("0X", STDOUT_FILENO);
			i += 2;
		}
	}
	return (i);
}

int	ft_format_before(enum e_c_flags c_flag, t_f_flags f_flags, unsigned int s)
{
	int	i;

	i = 0;
	if (c_flag == d_c_flag
		|| c_flag == i_c_flag
		|| c_flag == u_c_flag
		|| c_flag == x_c_flag
		|| c_flag == X_c_flag)
	{
		while (f_flags.dot_precision > s)
		{
			ft_putchar_fd('0', STDOUT_FILENO);
			i++;
			f_flags.dot_precision--;
		}
	}
	while (f_flags.field_width > (s + i) && !f_flags.minus_padding)
	{
		if (f_flags.zero_padding && !f_flags.is_precise)
			ft_putchar_fd('0', STDOUT_FILENO);
		else
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	return (i);
}

int	ft_format_after(t_f_flags f_flags, unsigned int size)
{
	int	i;

	i = 0;
	while (f_flags.field_width > (size + i) && f_flags.minus_padding)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	return (i);
}
