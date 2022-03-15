/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dot_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:22:19 by seb               #+#    #+#             */
/*   Updated: 2022/03/15 20:03:19 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_parse_dot_precision(const char **f, t_flags *flags)
{
	(*f)++;
	flags->is_precise = 1;
	flags->dot_precision = ft_get_flag_arg(f);
}
