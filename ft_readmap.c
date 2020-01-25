/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:54:19 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/25 19:12:56 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	matrix2(int fd, char *line, t_cub *cub, int i)
{
	int j;

	j = 0;
	while (line[j])
	{
		cub->matrix[i][j] = line[j] - '0';
		j++;
	}
}

void		ft_create_matrix(int fd, char *line, t_cub *cub)
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
				cub->pos_x = i;
				cub->pos_y = j;
				ft_dir(cub, line[j]);
			}
			else if (line[j])
			{
				if (line[j] == '2')
				{
					cub->sprite_posx = i;
					cub->sprite_posy = j;
				}
				cub->matrix[i][j] = line[j] - '0';
			}
			j++;
		}
		i++;
	}
	matrix2(fd, line, cub, i);
}

static void	ft_dir2(t_cub *cub, char c)
{
	if (c == 'E')
	{
		cub->dir_x = 0;
		cub->dir_y = 1;
		cub->plane_x = 0.66;
		cub->plane_y = 0;
	}
	else if (c == 'W')
	{
		cub->dir_x = 0;
		cub->dir_y = -1;
		cub->plane_x = -0.66;
		cub->plane_y = 0;
	}
}

void		ft_dir(t_cub *cub, char c)
{
	if (c == 'N')
	{
		cub->dir_x = -1;
		cub->dir_y = 0;
		cub->plane_x = 0;
		cub->plane_y = 0.66;
	}
	else if (c == 'S')
	{
		cub->dir_x = 1;
		cub->dir_y = 0;
		cub->plane_x = 0;
		cub->plane_y = -0.66;
	}
	else
		ft_dir2(cub, c);
}
