/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:07:47 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/11 22:44:48 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_itohex(unsigned long nb)
{
	unsigned long 	quotient;
	char			*hex;
	char			*s;
	char			*tmp;

	if (!nb)
	{
		s = ft_calloc(2, sizeof(char));
		if (!s)
			return (NULL);
		s[0] = '0';
	}
	else
	{
		s = ft_calloc(1, sizeof(char));
		if (!s)
			return (NULL);
		hex = "0123456789ABCDEF";
		quotient = nb;
		while (quotient)
		{
			tmp = malloc(sizeof(char) * (ft_strlen(s) + 2));
			if (!tmp)
				return (0);
			tmp[0] = hex[quotient % 16];
			ft_strlcpy(tmp + 1, s, ft_strlen(s) + 1);
			free(s);
			s = tmp;
			quotient /= 16;
		}
	}
	return (s);
}
