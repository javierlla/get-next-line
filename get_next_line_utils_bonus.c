/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:51:08 by jllarena          #+#    #+#             */
/*   Updated: 2023/12/11 12:00:29 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_gnlcalloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	dst = malloc(size * count);
	if (!dst)
	{
		return (0);
	}
	while (i < (size * count))
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}

char	*ft_gnlstrjoin(char *s1, char const *s2)
{
	char	*str12;
	size_t	size_str12;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (s1 == 0 || s2 == 0)
		return (0);
	size_str12 = i + j + 1;
	str12 = malloc(sizeof (char) * size_str12);
	if (!str12)
		return (0);
	ft_gnlstrlcpy(str12, s1, i + 1);
	ft_gnlstrlcat(str12, s2, size_str12);
	return (str12);
}

size_t	ft_gnlstrlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_gnlstrlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	origen;
	size_t	destino;

	i = 0;
	origen = 0;
	destino = 0;
	while (src[origen] != '\0')
		origen++;
	while (dst[destino] != '\0')
		destino++;
	if (dstsize <= destino || dstsize == 0)
	{
		return (dstsize + origen);
	}
	while (dstsize > (destino + 1 + i) && src[i] != '\0')
	{
		dst[destino + i] = src[i];
		i++;
	}
	dst[destino + i] = '\0';
	return (destino + origen);
}

char	*ft_gnlstrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return (&str[i]);
	}
	return (0);
}
