/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:57:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/24 20:19:09 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	hit(t_cub *cub)
{
	while (cub->hit == 0)
	{
		if (cub->sideDistX < cub->sideDistY)
		{
			cub->sideDistX += cub->deltaDistX;
			cub->mapX += cub->stepX;
			cub->side = 0;
		}
		else
		{
			cub->sideDistY += cub->deltaDistY;
			cub->mapY += cub->stepY;
			cub->side = 1;
		}
		if (cub->matrix[cub->mapX][cub->mapY] > 0)
			cub->hit = 1;
	}
}

static void	cubside2(t_cub *cub)
{
	if (cub->hit == 1)
	{
		if (cub->side == 0 && cub->posX > cub->mapX)
			cub->side = 6;
		else if (cub->side == 1 && cub->posY < cub->mapY)
			cub->side = 3;
	}
	cub->id = cub->matrix[cub->mapX][cub->mapY] + cub->side;
	cub->wallX -= floor((cub->wallX));
	cub->texX = abs((int)(cub->wallX * (double)(64)));
	ft_crouch_jump(cub);
}

static void	wall_texture(t_cub *cub, int x)
{
	while (cub->drawStart <= cub->drawEnd)
	{
		cub->texY = abs((((cub->drawStart * 256 - cub->height * 128 +
					cub->lineHeight * 128) * 64) / cub->lineHeight) / 256);
		ft_memcpy(cub->data + 4 * cub->width * cub->drawStart + x * 4,
				&cub->tex[cub->id].data[cub->texY % cub->height *
				cub->tex[cub->id].size_line + cub->texX % cub->width *
				cub->tex[cub->id].bpp / 8], sizeof(int));
		cub->drawStart++;
	}
}

static void	cubside(t_cub *cub)
{
	if (cub->side == 0)
		cub->perpWalldist = (cub->mapX - cub->posX +
		(1 - cub->stepX) / 2) / cub->rayDirX;
	else
		cub->perpWalldist = (cub->mapY - cub->posY +
		(1 - cub->stepY) / 2) / cub->rayDirY;
	cub->lineHeight = (int)(cub->height / cub->perpWalldist);
	cub->drawStart = -cub->lineHeight / 2 + cub->height / 2;
	if (cub->drawStart < 0)
		cub->drawStart = 0;
	cub->drawEnd = cub->lineHeight / 2 + cub->height / 2;
	if (cub->drawEnd >= cub->height)
		cub->drawEnd = cub->height - 1;
	if (cub->side == 0)
		cub->wallX = cub->posY + cub->perpWalldist * cub->rayDirY;
	else
		cub->wallX = cub->posX + cub->perpWalldist * cub->rayDirX;
}

int			ft_loop(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	ft_movement(cub);
	cub->img = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
	cub->data = mlx_get_data_addr(cub->img, &cub->bpp,
	&cub->size_line, &cub->endian);
	draw_sky(cub);
	while (x < cub->width)
	{
		y = 0;
		init_values(cub, x);
		next_step(cub);
		hit(cub);
		cubside(cub);
		cubside2(cub);
		wall_texture(cub, x);
		ft_crouch_jump(cub);
		x++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0);
	draw_gun(cub);
	fps(cub);
	return (0);
}
