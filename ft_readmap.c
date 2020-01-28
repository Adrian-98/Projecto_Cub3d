/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:54:19 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/28 16:00:41 by amunoz-p         ###   ########.fr       */
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

			if (line[j] == 'W' || line[j] == 'N'
				|| line[j] == 'S' || line[j] == 'E')
			{
				cub->matrix[i][j] = 0;
				cub->pos_x = i;
				cub->pos_y = j;
				ft_dir(cub, line[j]);
			}
			else if (line[j] >= '0' && line[j] <= '9')
			{
				if (line[j] == '2')
					cub->sprite_count += 16;
				cub->matrix[i][j] = line[j] - '0';
			}
			else
				break ;
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
