/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:57:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/31 19:25:00 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void		hit(t_cub *cub)
{
	while (cub->hit == 0)
	{
		if (cub->sidedist_x < cub->sidedist_y)
		{
			cub->sidedist_x += cub->deltadist_x;
			cub->map_x += cub->step_x;
			cub->side = 0;
		}
		else
		{
			cub->sidedist_y += cub->deltadist_y;
			cub->map_y += cub->step_y;
			cub->side = 1;
		}
		if (cub->matrix[cub->map_x][cub->map_y] == '1')
			cub->hit = 1;
		if (cub->matrix[cub->map_x][cub->map_y] == '2')
		{
			cub->sprite_on = 1;
			cub->sprite_posx = cub->map_x;
			cub->sprite_posy = cub->map_y;
		}
	}
}

static void		cubside2(t_cub *cub)
{
	if (cub->hit == 1)
	{
		if (cub->side == 0 && cub->pos_x > cub->map_x)
			cub->side = 6;
		else if (cub->side == 1 && cub->pos_y < cub->map_y)
			cub->side = 3;
	}
	cub->id = cub->matrix[cub->map_x][cub->map_y] + cub->side - '0';
	cub->wall_x -= floor((cub->wall_x));
	cub->tex_x = abs((int)(cub->wall_x * (double)(64)));
	ft_crouch_jump(cub);
}

static void		wall_texture(t_cub *cub, int x)
{
	while (cub->drawstart <= cub->drawend)
	{
		cub->tex_y = abs((((cub->drawstart * 256 - cub->height * 128 +
					cub->lineHeight * 128) * 64) / cub->lineHeight) / 256);
		ft_memcpy(cub->data + 4 * cub->width * cub->drawstart + x * 4,
				&cub->tex[cub->id].data[cub->tex_y % cub->height *
				cub->tex[cub->id].size_line + cub->tex_x % cub->width *
				cub->tex[cub->id].bpp / 8], sizeof(int));
		cub->drawstart++;
	}
}

void			process(t_cub *cub, int x)
{
	init_values(cub, x);
	next_step(cub);
	hit(cub);
	cubside(cub);
	cubside2(cub);
	wall_texture(cub, x);
	ft_crouch_jump(cub);
}

int				ft_loop(t_cub *cub)
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
		process(cub, x);
		cub->zbuffer[x] = cub->perpwalldist;
		x++;
	}
	if (cub->sprite_on == 1)
		draw_sprites(cub);
	if (cub->player.life <= 0.0)
		game_over(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0);
	kill(cub);
	draw_gun(cub);
	return (0);
}
