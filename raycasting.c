/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:57:01 by amunoz-p          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/25 13:50:09 by amunoz-p         ###   ########.fr       */
=======
/*   Updated: 2020/01/19 20:59:18 by adrian           ###   ########.fr       */
>>>>>>> c3041d79049f1426fdcf9c91275b94d12f0e9ee9
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

<<<<<<< HEAD
void	ft_verLine(int x, int y, t_cub *cub)
{
	// if (y < cub->drawStart)
	// 	ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
	// 		&cub->sky_color, sizeof(int));
	if (y > cub->drawEnd)
		ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
			&cub->floor_color, sizeof(int));
}

void		draw_sky(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->tex[6].img,
	-cub->test * 21, -2000 + Y / 3 - cub->rotY);
=======
// void		draw_sky(t_cub *cub)
// {
// 	int x;
// 	int y;
// 	x = 0;
// 	const double PI =  3.1415926;
// 	int aux;
	
// 	double imgx;
// 	int center;
// 	int cotainf;
// 	int cotasup;
// 	int delay = (66 * 660/ 360) / 2;
	
// 	imgx = (double)((int)(acos(cub->dirX)*180/PI)) * 660.0 / 360.0;
// 	center = (int)imgx;
// 	cotainf = (int)(imgx - delay) % 660;
// 	cotasup = (int)(imgx + delay) % 660; 
// 	if (center == 0)
// 		printf("hola\n");
	
// 	while (x < cub->width)
// 	{
// 		y = 0;
// 		while (y < cub->height / 2)
// 		{
// 			imgx = (double)(1.0 - (double)x/(cub->width))*(double)cotainf + (double)((double)x/((double)cub->width))*(double)cotasup;
// 			imgx = (int)imgx;
// 			ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
// 					&cub->tex[6].data[y % 218 * cub->tex[6].size_line +
// 					((int)imgx) % 660 * cub->tex[6].bpp / 8], sizeof(int));
// 			y++;
// 		}
// 		x++;
// 	}
// }

void		draw_sky(t_cub *cub)
{
	int x = 0;
	int y;
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
>>>>>>> c3041d79049f1426fdcf9c91275b94d12f0e9ee9
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


int		ft_loop(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	
	ft_movement(cub);
	cub->img = mlx_new_image (cub->mlx_ptr, cub->width, cub->height);
	cub->data = mlx_get_data_addr(cub->img, &cub->bpp, &cub->size_line, &cub->endian);
	
	while (x < cub->width)
	{
		y = 0;
		init_values(cub, x);
		next_step(cub);
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
		if (cub->side == 0)
				cub->perpWalldist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2) / cub->rayDirX;
		else
			cub->perpWalldist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2) / cub->rayDirY;
		cub->lineHeight = (int)(cub->height / cub->perpWalldist);
		cub->drawStart = -cub->lineHeight / 2 + cub->height / 2;
		if (cub->drawStart < 0)
			cub->drawStart = 0;
		cub->drawEnd = cub->lineHeight / 2 + cub->height / 2;
		if (cub->drawEnd >= cub->height)
			cub->drawEnd = cub->height - 1;
				
		//x coordenate on the texture
		cub->id = cub->matrix[cub->mapX][cub->mapY] + cub->side * 2;

		if (cub->side == 0)
			cub->wallX = cub->posY + cub->perpWalldist * cub->rayDirY;
		else
			cub->wallX = cub->posX + cub->perpWalldist * cub->rayDirX;
	
		cub->wallX -= floor((cub->wallX));
		cub->texX = abs((int)(cub->wallX * (double)(64)));
		ft_crouch_jump(cub);
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
		ft_crouch_jump(cub);
		x++;
	}
	mlx_put_image_to_window (cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0);
	draw_sky(cub);
	return (0);	
}