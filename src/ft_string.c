/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:53:47 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 12:57:13 by seb              ###   ########.fr       */
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
