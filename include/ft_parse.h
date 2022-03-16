/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:19:45 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 17:40:58 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include <ft_flags.h>

void	ft_parse_alternate_form(const char **f, t_f_flags *ff);
void	ft_parse_left_blank(const char **f, t_f_flags *ff);
void	ft_parse_plus_sign(const char **f, t_f_flags *ff);
void	ft_parse_zero_padding(const char **f, t_f_flags *ff);
void	ft_parse_minus_padding(const char **f, t_f_flags *ff);
void	ft_parse_dot_precision(const char **f, t_f_flags *ff);

#endif
