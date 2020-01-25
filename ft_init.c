/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:03:17 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/25 12:48:43 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	init_values(t_cub *cub, int x)
{
	cub->wall_color = 0x56050;
	cub->hit = 0;
	cub->camera_x = 2 * x / (double)cub->width - 1;
	cub->raydir_x = cub->dir_x + cub->plane_x * cub->camera_x;
	cub->raydir_y = cub->dir_y + cub->plane_y * cub->camera_x;
	cub->map_x = (int)cub->pos_x;
	cub->map_y = (int)cub->pos_y;
	cub->deltadist_x = fabs(1 / cub->raydir_x);
	cub->deltadist_y = fabs(1 / cub->raydir_y);
}

void	draw_sky(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	while (x < cub->width)
	{
		y = 0;
		while (y < cub->height / 2)
		{
			ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
				&cub->tex[6].data[y % 512 * cub->tex[6].size_line +
				x % 512 * cub->tex[6].bpp / 8], sizeof(int));
			y++;
		}
		while (y < cub->height)
		{
			ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
			&cub->tex[9].data[y % 218 * cub->tex[9].size_line +
			x % 512 * cub->tex[9].bpp / 8], sizeof(int));
			y++;
		}
		x++;
	}
}

void	next_step(t_cub *cub)
{
	if (cub->raydir_x < 0)
	{
		cub->step_x = -1;
		cub->sidedist_x = (cub->pos_x - cub->map_x) * cub->deltadist_x;
	}
	else
	{
		cub->step_x = 1;
		cub->sidedist_x = (cub->map_x + 1.0 - cub->pos_x) * cub->deltadist_x;
	}
	if (cub->raydir_y < 0)
	{
		cub->step_y = -1;
		cub->sidedist_y = (cub->pos_y - cub->map_y) * cub->deltadist_y;
	}
	else
	{
		cub->step_y = 1;
		cub->sidedist_y = (cub->map_y + 1.0 - cub->pos_y) * cub->deltadist_y;
	}
}
