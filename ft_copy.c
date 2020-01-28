/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:33:40 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/28 17:46:38 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void		ft_copy2(char *line, t_cub *cub, int j, int i)
{
	if (line[0] == 'S' && line[1] == 'O')
	{
		j = 3;
		cub->south = ft_strdup(&line[j]);
	}
	else if (line[0] == 'S')
	{
		j = 2;
		cub->spriteee = ft_strdup(&line[j]);
	}
	else if (line[j] == 'W' || line[j] == 'N'
			|| line[j] == 'S' || line[j] == 'E')
	{
		cub->matrix[i][j] = 0;
		cub->pos_x = i;
		cub->pos_y = j;
		ft_dir(cub, line[j]);
	}
}

void		ft_copy(char *line, t_cub *cub, int j, int i)
{
	if (line[0] == 'R')
	{
		j = 2;
		cub->width = ft_atoi(&line[j]);
		while (line[j] != ' ')
			j++;
		cub->height = ft_atoi(&line[j]);
	}
	else if (line[0] == 'N')
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
	else
		ft_copy2(line, cub, j, i);
}
