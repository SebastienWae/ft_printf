/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:07:47 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/12 16:10:06 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_dectobase(unsigned long dec, char *base, unsigned int base_size)
{
	unsigned long	quotient;
	char			*s;
	char			*tmp;

	s = ft_calloc(1, sizeof(char));
	if (!s)
		return (NULL);
	quotient = dec;
	while (quotient)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(s) + 2));
		if (!tmp)
			return (0);
		tmp[0] = base[quotient % base_size];
		ft_strlcpy(tmp + 1, s, ft_strlen(s) + 1);
		free(s);
		s = tmp;
		quotient /= base_size;
	}
	return (s);
}

char	*ft_dectohex(unsigned long dec)
{
	char			*s;
	char			*hex;

	if (!dec)
	{
		s = ft_calloc(2, sizeof(char));
		if (!s)
			return (NULL);
		s[0] = '0';
	}
	else
	{
		hex = "0123456789abcdef";
		s = ft_dectobase(dec, hex, 16);
	}
	return (s);
}
