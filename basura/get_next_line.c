/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:44:44 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/31 18:55:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

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







