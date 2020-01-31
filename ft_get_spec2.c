/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:12:24 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/31 19:18:38 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	get_spec(t_cub *cub)
{
	if (!(ft_get_coord(cub)) || !(ft_get_camangle(cub)))
		ft_error();
	if (!cub->col_floor || !cub->resol
		|| cub->width > 1920 || cub->height > 1080 || !cub->north ||
		!cub->west || !cub->east || !cub->south || !cub->spriteee
		|| (ft_check_map_content_and_size(cub->matrix) +
		ft_check_map_border(cub->matrix)) != 2)
		ft_error();
}

int		ft_get_spec(t_cub *cub, int fd)
{
	char *tmp;
	char *line;

	while (get_next_line(fd, &line) == 1)
	{
		tmp = line;
		(line[0] == 'R' && line[1] == ' ') ? ft_get_res(line, cub) : 0;
		(line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ?
				cub->north = ft_strdup(line + 3) : 0;
		(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ?
				cub->south = ft_strdup(line + 3) : 0;
		(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ?
				cub->west = ft_strdup(line + 3) : 0;
		(line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ?
				cub->east = ft_strdup(line + 3) : 0;
		(line[0] == 'S' && line[1] == ' ')
		? cub->spriteee = ft_strdup(line + 2) : 0;
		(line[0] == 'F' && line[1] == ' ')
		? cub->col_floor = ft_get_col(line) : 0;
		(line[0] == '1') ? ft_get_map(cub, &line, fd) : 0;
		free(tmp);
	}
	get_spec(cub);
	return (1);
}

static void	position(t_cub *cub)
{
	if (cub->dir == 'N')
	{
		cub->dir_x = -1;
		cub->dir_y = 0;
		cub->plane_x = 0;
		cub->plane_y = 0.66;
	}
	else if (cub->dir == 'W')
	{
		cub->dir_x = 0;
		cub->dir_y = -1;
		cub->plane_x = -0.66;
		cub->plane_y = 0;
	}
}

int		ft_get_camangle(t_cub *cub)
{
	if (cub->dir == 'N')
		position(cub);
	else if (cub->dir == 'W')
		position(cub);
	else if (cub->dir == 'S')
	{
		cub->dir_x = 1;
		cub->dir_y = 0;
		cub->plane_x = 0;
		cub->plane_y = -0.66;
	}
	else if (cub->dir == 'E')
	{
		cub->dir_x = 0;
		cub->dir_y = 1;
		cub->plane_x = 0.66;
		cub->plane_y = 0;
	}
	else
		return (0);
	return (1);
}
