/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:09:07 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 14:35:12 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_BONUS_H
# define FT_FORMAT_BONUS_H

#include <ft_flags.h>

int	ft_format_insert_char(t_f_flags f_flags);
int	ft_format_alternate_form(enum e_c_flags c_flag, t_f_flags f_flags);
int	ft_format_before(enum e_c_flags c_flag, t_f_flags f_flags, unsigned int size);
int	ft_format_after(t_f_flags f_flags, unsigned int size);

#endif
