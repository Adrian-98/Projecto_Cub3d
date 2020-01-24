/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:00:54 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/24 20:19:56 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	ft_walk_front(t_cub *cub)
{
	if (cub->matrix[(int)(cub->posX + cub->dirX *
	cub->movespeed)][(int)cub->posY] == 0)
		cub->posX = cub->posX + cub->dirX * cub->movespeed;
	if (cub->matrix[(int)cub->posX][(int)(cub->posY +
	cub->dirY * cub->movespeed)] == 0)
		cub->posY = cub->posY + cub->dirY * cub->movespeed;
}

static void	ft_walk_back(t_cub *cub)
{
	if (cub->matrix[(int)(cub->posX - cub->dirX *
	cub->movespeed)][(int)cub->posY] == 0)
		cub->posX = cub->posX - cub->dirX * cub->movespeed;
	if (cub->matrix[(int)cub->posX][(int)(cub->posY -
	cub->dirY * cub->movespeed)] == 0)
		cub->posY = cub->posY - cub->dirY * cub->movespeed;
}

static void	ft_rotate_right(t_cub *cub)
{
	cub->oldDirX = cub->dirX;
	cub->dirX = cub->dirX * cos(-(cub->rotatespeed)) -
	cub->dirY * sin(-(cub->rotatespeed));
	cub->dirY = cub->oldDirX * sin(-(cub->rotatespeed)) +
	cub->dirY * cos(-(cub->rotatespeed));
	cub->oldPlaneX = cub->planeX;
	cub->planeX = cub->planeX * cos(-(cub->rotatespeed)) -
	cub->planeY * sin(-(cub->rotatespeed));
	cub->planeY = cub->oldPlaneX * sin(-(cub->rotatespeed)) +
	cub->planeY * cos(-(cub->rotatespeed));
}

static void	ft_rotate_left(t_cub *cub)
{
	cub->oldDirX = cub->dirX;
	cub->dirX = cub->dirX * cos(cub->rotatespeed) -
	cub->dirY * sin(cub->rotatespeed);
	cub->dirY = cub->oldDirX * sin(cub->rotatespeed) +
	cub->dirY * cos(cub->rotatespeed);
	cub->oldPlaneX = cub->planeX;
	cub->planeX = cub->planeX * cos(cub->rotatespeed) -
	cub->planeY * sin(cub->rotatespeed);
	cub->planeY = cub->oldPlaneX * sin(cub->rotatespeed) +
	cub->planeY * cos(cub->rotatespeed);
}

void		ft_movement(t_cub *cub)
{
	if (cub->walk_front == 1)
		ft_walk_front(cub);
	if (cub->walk_back == 1)
		ft_walk_back(cub);
	if (cub->walk_left == 1)
		ft_walk_left(cub);
	if (cub->walk_right == 1)
		ft_walk_right(cub);
	if (cub->rotate_left == 1)
		ft_rotate_left(cub);
	if (cub->rotate_right == 1)
		ft_rotate_right(cub);
}
