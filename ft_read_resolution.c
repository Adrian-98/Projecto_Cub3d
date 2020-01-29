/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:32:48 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/29 16:25:56 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void			ft_read1(char *line, t_cub *cub, int j)
{
	if (line[0] == 'N')
	{
		j = 3;
		cub->north = ft_strdup(&line[j]);
	}
	else if (line[0] == 'W')
	{
		j = 3;
		cub->west = ft_strdup(&line[j]);
	}
	else if (line[0] == 'E')
	{
		j = 3;
		cub->east = ft_strdup(&line[j]);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		j = 3;
		cub->south = ft_strdup(&line[j]);
	}
	else if (line[0] == 'S')
	{
		j = 2;
		cub->spriteee = ft_strdup(&line[j]);
	}
}

void				ft_read_resolution(int fd, char *line, t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	while (get_next_line(fd, &line) > 0 && i < 8)
	{
		j = 0;
		if (line[0] == 'R')
		{
			j = 2;
			cub->width = ft_atoi(&line[j]);
			while (line[j] != ' ')
				j++;
			cub->height = ft_atoi(&line[j]);
		}
		else if (line[0] == ' ')
			break ;
		else
			ft_read1(line, cub, j);
		i++;
		free(line);
	}
}
