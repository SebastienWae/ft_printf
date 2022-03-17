/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:53:47 by seb               #+#    #+#             */
/*   Updated: 2022/03/17 13:03:25 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strappend(char *src, char *appendix)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(appendix) + 1));
	i = 0;
	while (*src)
		str[i++] = *src++;
	while (*appendix)
		str[i++] = *appendix++;
	str[i] = 0;
	return (str);
}

char	*ft_strprepend(char *src, char *prefix)
{
	return (ft_strappend(prefix, src));
}

char	*ft_utoa(unsigned int nb)
{
	char	*tmp;
	char	*tmp2;
	char	*str;

	if (nb > 2147483647)
	{
		tmp = ft_itoa(nb / 10);
		tmp2 = ft_itoa(nb % 10);
		str = ft_strappend(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
		str = ft_itoa(nb);
	return (str);
}
