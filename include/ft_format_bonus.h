/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:09:07 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 17:40:39 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_BONUS_H
# define FT_FORMAT_BONUS_H

# include <ft_flags.h>

int	ft_format_insert_char(t_f_flags f);
int	ft_format_alternate_form(enum e_c_flags c, t_f_flags f);
int	ft_format_before(enum e_c_flags c, t_f_flags f, unsigned int s);
int	ft_format_after(t_f_flags f, unsigned int s);

#endif
