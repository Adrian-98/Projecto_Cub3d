/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:44:44 by glopez-a          #+#    #+#             */
/*   Updated: 2019/12/18 19:10:29 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libcub.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s3;

	if (s1 && s2)
	{
		i = (ft_strlen(s1) + ft_strlen(s2));
		s3 = malloc(sizeof(char) * (i + 1));
		if (s3 == 0)
			return (0);
		ft_strcpy(s3, (char *)s1);
		ft_strcat(s3, (char *)s2);
		return (s3);
	}
	return (0);
}

static int	get_line(char **line, char *aux, int i)
{
	char	*aux1;

	if (i < 0)
		return (-1);
	if (!*aux && !i)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((aux1 = ft_strchr(aux, '\n')))
	{
		*aux1 = 0;
		*line = ft_strdup(aux);
		aux = 0;
	}
	else
	{
		*line = aux;
		aux = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{		
	int			i;
	static char	*aux;
	char		buff[2];
	char		*tmp;

	aux = 0;
	if (fd < 0 || line == 0)
		return (-1);
	while ((i = read(fd, buff, 1)) > 0)
	{
		buff[1] = '\0';
		if (!aux)
			aux = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(aux, buff);
			free(aux);
			aux = tmp;
		}
		if (ft_strchr(aux, '\n'))
			break ;
	}
	return (get_line(line, aux, i));
}

