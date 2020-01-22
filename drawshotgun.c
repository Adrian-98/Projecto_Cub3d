/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshotgun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:11:02 by adrian            #+#    #+#             */
/*   Updated: 2020/01/22 15:20:41 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	animate_shotgun(t_cub *cub, int posx, int posy)
{
	if (cub->player.fr >= 15 && cub->player.reload == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->tex[16].img, posx, posy);
	else if (cub->player.fr >= 12 && cub->player.fr <= 14
		&& cub->player.reload == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->tex[17].img, posx, posy);
	else if (cub->player.fr >= 10 && cub->player.fr <= 11
		&& cub->player.reload == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->tex[18].img, posx, posy);
	else if (cub->player.fr >= 7 && cub->player.fr <= 9 && cub->player.reload == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->tex[19].img, posx, posy);
	else if (cub->player.fr >= 5 && cub->player.fr <= 7 && cub->player.reload == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->tex[19].img, posx, posy);
	else if (cub->player.fr >= 1 && cub->player.fr <= 4 && cub->player.reload == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->tex[17].img, posx, posy);
	cub->player.fr--;
	if (cub->player.fr == 1)
	{
		cub->player.fr = 17;
		cub->player.shooting = 0;
		if (cub->player.reload == 1)
		{
			cub->player.bullets = 8;
			cub->player.reload = 0;
		}
	}
}

void		draw_gun(t_cub *cub)
{
	int posx;
	int posy;

	posx = (cub->width - 400) / 2;
	posy = cub->height - 400;
	if (cub->player.shooting == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->tex[15].img, posx, posy);
	else
	{
		if (cub->player.fr == 17 && (cub->player.fr--))
		{
			if (cub->player.bullets > 0)
			{
				cub->player.bullets--;
				system("afplay ./sounds/shot.mp3& 2&>/dev/null >/dev/null");
			}
			else
				cub->player.reload = 1;
		}
		animate_shotgun(cub, posx, posy);
	}
}