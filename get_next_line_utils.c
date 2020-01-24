/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:20:44 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/24 20:17:47 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = c;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = (char *)malloc(sizeof(char) * i + 1);
	if (s2 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] != 0)
		i++;
	while (src[j] != 0)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (dst);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
