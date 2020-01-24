/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:03:17 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/24 20:09:34 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	init_values(t_cub *cub, int x)
{
	cub->wall_color = 0x56050;
	cub->hit = 0;
	cub->cameraX = 2 * x / (double)cub->width - 1;
	cub->rayDirX = cub->dirX + cub->planeX * cub->cameraX;
	cub->rayDirY = cub->dirY + cub->planeY * cub->cameraX;
	cub->mapX = (int)cub->posX;
	cub->mapY = (int)cub->posY;
	cub->deltaDistX = fabs(1 / cub->rayDirX);
	cub->deltaDistY = fabs(1 / cub->rayDirY);
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
	if (cub->rayDirX < 0)
	{
		cub->stepX = -1;
		cub->sideDistX = (cub->posX - cub->mapX) * cub->deltaDistX;
	}
	else
	{
		cub->stepX = 1;
		cub->sideDistX = (cub->mapX + 1.0 - cub->posX) * cub->deltaDistX;
	}
	if (cub->rayDirY < 0)
	{
		cub->stepY = -1;
		cub->sideDistY = (cub->posY - cub->mapY) * cub->deltaDistY;
	}
	else
	{
		cub->stepY = 1;
		cub->sideDistY = (cub->mapY + 1.0 - cub->posY) * cub->deltaDistY;
	}
}
