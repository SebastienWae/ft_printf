/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:10:28 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 12:32:21 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

char	*ft_strappend(char *src, char *appendix);
char	*ft_strprepend(char *src, char *prefix);

char	*ft_dectobase(unsigned long dec, char *base, unsigned int base_size);
char	*ft_dectohex(unsigned long dec);

char	*ft_utoa(unsigned int nb);

#endif
