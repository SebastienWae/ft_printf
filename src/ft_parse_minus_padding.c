/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_minus_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:22:19 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 17:43:14 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>

void	ft_parse_minus_padding(const char **f, t_f_flags *flags)
{
	(*f)++;
	flags->minus_padding = 1;
}
