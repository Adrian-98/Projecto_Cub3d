/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:11:52 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/28 17:39:43 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	calculate_sprites(t_cub *cub)
{
	cub->inv_det = 1.0 / (cub->plane_x * cub->dir_y -
	cub->dir_x * cub->plane_y);
	cub->transform_x = cub->inv_det * (cub->dir_y *
		cub->sprite_x - cub->dir_x * cub->sprite_y);
	cub->transform_y = cub->inv_det * (-cub->plane_y *
		cub->sprite_x + cub->plane_x * cub->sprite_y);
	cub->sprite_screen_x = (int)((cub->width / 2) *
		(1 + cub->transform_x / cub->transform_y));
	cub->sprite_height = abs((int)(cub->height / cub->transform_y));
	cub->draw_start_y = -cub->sprite_height / 2 + cub->height / 2;
	if (cub->draw_start_y < 0)
		cub->draw_start_y = 0;
	cub->draw_end_y = cub->sprite_height / 2 + cub->height / 2;
	if (cub->draw_end_y >= cub->height)
		cub->draw_end_y = cub->height - 1;
	cub->sprite_width = abs((int)(cub->height / cub->transform_y));
	cub->draw_start_x = -cub->sprite_width / 2 + cub->sprite_screen_x;
	if (cub->draw_start_x < 0)
		cub->draw_start_x = 0;
	cub->draw_end_x = cub->sprite_width / 2 + cub->sprite_screen_x;
	if (cub->draw_end_x >= cub->width)
		cub->draw_end_x = cub->width - 1;
}

void		draw_sprites(t_cub *cub)
{
	int x;
	int y;

	cub->sprite_x = (double)cub->sprite_posx - cub->pos_x;
	cub->sprite_y = (double)cub->sprite_posy - cub->pos_y;
	calculate_sprites(cub);
	x = cub->draw_start_x - 1;
	while (++x < cub->draw_end_x)
	{
		cub->tex_x = (int)(256 * (x - (-cub->sprite_width / 2 +
		cub->sprite_screen_x)) * texWidth / cub->sprite_width) / 256;
		y = cub->draw_start_y;
		if (cub->transform_y > 0 && x > 0 && x < cub->width
			&& cub->transform_y < cub->zbuffer[x])
		{
			while (y < cub->draw_end_y)
			{
				cub->tex_y = abs((((y * 256 - cub->height * 128 +
					cub->sprite_height * 128) * texHeight) /
					cub->sprite_height) / 256);
				if ((cub->tex[20].data[cub->tex_y % 64 *
					cub->tex[20].size_line + cub->tex_x % 64 *
					cub->tex[20].bpp / 8] != 0))
				{
					ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
						&cub->tex[20].data[cub->tex_y % 64 *
						cub->tex[20].size_line + cub->tex_x % 64 *
						cub->tex[20].bpp / 8], sizeof(int));
				}
				y++;
			}
		}
	}
}

void		kill(t_cub *cub)
{
	printf("%d\n", cub->sprite_count);
	if (cub->sprite_on == 1)
	{
		if (cub->pos_x <= cub->sprite_posx + 4 &&
			cub->pos_x >= cub->sprite_posx - 4 && cub->pos_y
			<= cub->sprite_posy + 4 &&
			cub->pos_y >= cub->sprite_posy - 4)
		{
			if (cub->player.life > 90 && cub->player.life < 100)
				system("afplay ./sounds/auch.mp3& 2&>/dev/null >/dev/null");
			if (cub->player.life < 0 && cub->player.life > -10)
				system("afplay ./sounds/gameover.mp3& 2&>/dev/null >/dev/null");
			cub->player.life = cub->player.life - 3;
		}
	}
	if (cub->pos_x <= cub->sprite_posx + 7 &&
		cub->pos_x >= cub->sprite_posx - 7 && cub->pos_y
		<= cub->sprite_posy + 7 &&
		cub->pos_y >= cub->sprite_posy - 7)
	{
		if (cub->player.shooting == 1 && cub->transform_x >= -0.5
		&& cub->transform_x <= 0.5)
		{
			cub->matrix[cub->sprite_posx][cub->sprite_posy] = 0;
			cub->sprite_on = 0;
			cub->sprite_count -= 1;
		}
	}
	if (cub->sprite_count <= 5 && cub->sprite_count > 4)
		system("afplay ./sounds/victory.mp3& 2&>/dev/null >/dev/null");
}
