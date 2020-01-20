/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:01:23 by marandre          #+#    #+#             */
/*   Updated: 2020/01/19 23:17:27 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	fill_struct(t_sprites_work *spw, t_cub *cub)
{
	spw->sp_x = cub->posX - cub->player->x_pos;
	spw->sp_y = cub->posY - cub->player->y_pos;
	spw->inv_det = 1.0 / (cub->planeX * cub->player->y_dir - cub->player->x_dir * cub->planeY);
	spw->transform_x = spw->inv_det *
		(cub->player->y_dir * spw->sp_x - cub->player->x_dir * spw->sp_y);
	spw->transform_y = spw->inv_det *
		(-cub->planeY * spw->sp_x + cub->planeX * spw->sp_y);
	spw->sp_screen_x = (int)((cub->window.window_width / 2) *
		(1 + spw->transform_x / spw->transform_y));
	spw->vms = (int)(96 / spw->transform_y);
	spw->sp_height = abs((int)(cub->window.window_height / (spw->transform_y))) / 1;
	spw->draw_start_y = -spw->sp_height / 2 +
		cub->window.window_height / 2 + spw->vms;
	if (spw->draw_start_y < 0)
		spw->draw_start_y = 0;
	spw->draw_end_y = spw->sp_height / 2 + cub->window.window_height / 2 + spw->vms;
	if (spw->draw_end_y >= cub->window.window_height)
		spw->draw_end_y = cub->window.window_height - 1;
	spw->sp_width = abs((int)(cub->window.window_height / (spw->transform_y))) / 1;
	spw->draw_start_x = -spw->sp_width / 2 + spw->sp_screen_x;
	if (spw->draw_start_x < 0)
		spw->draw_start_x = 0;
	spw->draw_end_x = spw->sp_width / 2 + spw->sp_screen_x;
	if (spw->draw_end_x >= cub->window.window_width)
		spw->draw_end_x = cub->window.window_width - 1;
}

static void	print_sprites(t_cub *cub, t_sprites_work *spw)
{
	spw->tex_x = (int)(256 * (spw->stripe - (-spw->sp_width / 2 +
		spw->sp_screen_x)) * 64 / spw->sp_width) / 256;
	if (spw->transform_y > 0 && spw->stripe > 0 && spw->stripe <
		cub->window.window_width && spw->transform_y < cub->zbuffer[spw->stripe])
	{
		spw->y = spw->draw_start_y - 1;
		while (++spw->y < spw->draw_end_y)
		{
			spw->d = (spw->y - spw->vms) * 256 - cub->window.window_height *
				128 + spw->sp_height * 128;
			spw->tex_y = ((spw->d * 64) / spw->sp_height) / 256;
			spw->color = cub->tex[11].data[spw->tex_y % 64 * cub->tex[11].size_line + spw->tex_x % 64 *
			cub->tex[11].bpp / 8];
			if ((spw->color & 0x00FFFFFF) != 0)
				ft_memcpy(cub->window.img_ptr + 4 * cub->window.window_width * spw->y +
					spw->stripe * 4, &cub->tex[11].
					data[spw->tex_y % 64 * cub->tex[11].size_line + spw->tex_x % 64 *
					cub->tex[11].bpp / 8], sizeof(int));
		}
	}
}

int			draw_player(t_cub *cub)
{
	t_sprites_work	*spw;

	if (!(spw = ft_calloc(sizeof(t_sprites_work), 1)))
		return (0);
    fill_struct(spw, cub);
    spw->stripe = spw->draw_start_x - 1;
    while (++spw->stripe < spw->draw_end_x)
        print_sprites(cub, spw);
	free(spw);
	return (1);
}