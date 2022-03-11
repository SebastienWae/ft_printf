/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:07:47 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/11 18:21:40 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_itohex(unsigned long nb, char *s)
{
	unsigned long 	quotient;
	int				i;
	char			*hex;

	hex = "0123456789ABCDEF";
	i = 0;
	quotient = nb;
	while (quotient)
	{
		s[i++] = hex[quotient % 16];
		quotient /= 16;
	}
	s[i] = 0;
	return (s);
}
