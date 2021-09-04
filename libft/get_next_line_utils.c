/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenijdrozdov <arsenijdrozdov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:00:24 by demilan           #+#    #+#             */
/*   Updated: 2021/09/04 19:55:58 by arsenijdroz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*d;

	if (dst == NULL && src == NULL)
		return (0);
	d = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		d[i] = sr[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t		len_str;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len_str = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len_str + 1));
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[len_str] = '\0';
	free(s1);
	return (str);
}
