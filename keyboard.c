/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:58:17 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/20 13:54:21 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		key_press(int keycode, t_cub *cub)
{
	if (keycode == 256)
	{
		cub->crouch = 1;
		cub->movespeed /= 2;
	}
	if (keycode == 49)
		cub->jump = 1;
	if (keycode == 257)
		cub->movespeed = cub->movespeed * 2;
	if (keycode == 13)
		cub->walk_front = 1;
	if (keycode == 1)
		cub->walk_back = 1;
	if (keycode == 123)
		cub->rotate_left = 1;
	if (keycode == 124)
		cub->rotate_right = 1;
	if (keycode == 0)
		cub->walk_left = 1;
	if (keycode == 2)
		cub->walk_right = 1;
	if (keycode == 53)
	{
		system("killall afplay 2&>/dev/null >/dev/null");
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
		exit(0);
	}
	//printf("%d\n", keycode);
	return (0);
}

int		key_realese(int keycode, t_cub *cub)
{
	if (keycode == 257)
		cub->movespeed = cub->movespeed / 2;
	if (keycode == 13)
		cub->walk_front = 0;
	if (keycode == 1)
		cub->walk_back = 0;
	if (keycode == 123)
		cub->rotate_left = 0;
	if (keycode == 124)
		cub->rotate_right = 0;
	if (keycode == 0)
		cub->walk_left = 0;
	if (keycode == 2)
	 	cub->walk_right = 0;
	if (keycode == 49)
		cub->jump = 0;
	if (keycode == 256)
	{
		cub->crouch = 0;
		cub->movespeed *= 2;
	}
	return (0);
}

int close_window(t_cub *cub)
{
    (void)cub;
	system("killall afplay 2&>/dev/null >/dev/null");
    exit(0);
}
