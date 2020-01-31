/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 19:01:41 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

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
		(line[0] == 'S' && line[1] == ' ') ? cub->spriteee = ft_strdup(line + 2) : 0;
		(line[0] == 'F' && line[1] == ' ') ? cub->col_floor = ft_get_col(line) : 0;
		(line[0] == '1') ? ft_get_map(cub, &line, fd) : 0;
		free(tmp);
	}
	if (!(ft_get_coord(cub)) || !(ft_get_camangle(cub)))
		return (0);
	if (!cub->col_floor || !cub->resol
		|| cub->width > 1920 || cub->height > 1080 || !cub->north ||
		!cub->west || !cub->east || !cub->south || !cub->spriteee
		|| (ft_check_map_content_and_size(cub->matrix) +
		ft_check_map_border(cub->matrix)) != 2)
		return (0);
	return (1);
}

int		ft_get_camangle(t_cub *cub)
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

int		ft_get_coord(t_cub *cub)
{
	int	col;
	int line;

	line = 0;
	col = 0;
	while (cub->matrix[line])
	{
		while (cub->matrix[line][col])
		{
			if (ft_check_in_set_char(cub->matrix[line][col], "WESN"))
			{
				cub->pos_x = line;
				cub->pos_y = col;
				cub->dir = cub->matrix[line][col];
				cub->matrix[line][col] = '0';
				return (1);
			}
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}

void ft_get_map(t_cub *cub, char **line, int fd)
{
	int		map_line;

	if (!(cub->matrix = (char **)ft_calloc(1000000, sizeof(char *))))
		ft_error();
	map_line = 0;
	cub->matrix[map_line] = ft_strdup(*line);
	map_line++;
	while (get_next_line(fd, line) == 1)
	{
		cub->matrix[map_line] = ft_strdup(*line);
		map_line++;
		free(*line);
	}
	cub->matrix[map_line] = ft_strdup(*line);
	free(*line);
	close (fd);
}

void		ft_get_res(char *line, t_cub *cub)
{
	int 	i_line;


	i_line = 0;
	while (!ft_isdigit(line[i_line]))
		i_line++;
	cub->width = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	i_line++;
	cub->height = ft_atoi(line + i_line);
}

int		ft_get_col(char *line)
{
	int 	i_line;
	char	*color;
	int		i_color;
	int		col;

	if (!(color = (char *)ft_calloc(10, sizeof(char))))
		return (0);
	i_color = 0;
	i_line = 2;
	while (line[i_line])
	{
		while (ft_isdigit(line[i_line]) == 0 && line[i_line])
			i_line++;
		while (ft_isdigit(line[i_line]) == 1 && line[i_line])
		{
			color[i_color++] = line[i_line++];
		}
	}
	if (ft_atoi(color) < 0 || ft_atoi(color) > 255255255)
		return (0);
	col = ft_atoi(color);
	free(color);
	return (col);
}
