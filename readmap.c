/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:54:19 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/14 17:56:07 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_create_matrix(int fd, char *line, t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		while (line[j])
		{
			if ('0' > line[j] || line[j] > '9')
				{
					cub->matrix[i][j] = 0;
					cub->posX = i;
					cub->posY = j;
					ft_dir(cub, line[j]);
				}
			else if (line[j])
				cub->matrix[i][j] = line[j] - '0';
			//printf("%i", cub->matrix[i][j]);
			j++;
		}
		//printf("\n");
		i++;
	}
	j = 0;
	while (line[j])
	{
		cub->matrix[i][j] = line[j] - '0';
		//printf("%i", cub->matrix[i][j]);
		j++;
	}
}

void	ft_dir(t_cub *cub, char c)
{
	if (c == 'N')
	{
		cub->dirX = -1;
		cub->dirY = 0;
		cub->planeX = 0;
		cub->planeY = 0.66;
	}
	else if (c == 'S')
	{
		cub->dirX = 1;
		cub->dirY = 0;
		cub->planeX = 0;
		cub->planeY = -0.66;
	}
	else if (c == 'E')
	{
		cub->dirX = 0;
		cub->dirY = 1;
		cub->planeX = 0.66;
		cub->planeY = 0;
	}
	else if (c == 'W')
	{
		cub->dirX = 0;
		cub->dirY = -1;
		cub->planeX = -0.66;
		cub->planeY = 0;
	}
}