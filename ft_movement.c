/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:00:54 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/30 18:34:55 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	ft_walk_front(t_cub *cub)
{
	if (cub->matrix[(int)(cub->pos_x + cub->dir_x *
	cub->movespeed)][(int)cub->pos_y] == '0')
		cub->pos_x = cub->pos_x + cub->dir_x * cub->movespeed;
	if (cub->matrix[(int)cub->pos_x][(int)(cub->pos_y +
	cub->dir_y * cub->movespeed)] == '0')
		cub->pos_y = cub->pos_y + cub->dir_y * cub->movespeed;
}

static void	ft_walk_back(t_cub *cub)
{
	if (cub->matrix[(int)(cub->pos_x - cub->dir_x *
	cub->movespeed)][(int)cub->pos_y] == '0')
		cub->pos_x = cub->pos_x - cub->dir_x * cub->movespeed;
	if (cub->matrix[(int)cub->pos_x][(int)(cub->pos_y -
	cub->dir_y * cub->movespeed)] == '0')
		cub->pos_y = cub->pos_y - cub->dir_y * cub->movespeed;
}

static void	ft_rotate_right(t_cub *cub)
{
	cub->olddir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(-(cub->rotatespeed)) -
	cub->dir_y * sin(-(cub->rotatespeed));
	cub->dir_y = cub->olddir_x * sin(-(cub->rotatespeed)) +
	cub->dir_y * cos(-(cub->rotatespeed));
	cub->oldplane_x = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(-(cub->rotatespeed)) -
	cub->plane_y * sin(-(cub->rotatespeed));
	cub->plane_y = cub->oldplane_x * sin(-(cub->rotatespeed)) +
	cub->plane_y * cos(-(cub->rotatespeed));
}

static void	ft_rotate_left(t_cub *cub)
{
	cub->olddir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(cub->rotatespeed) -
	cub->dir_y * sin(cub->rotatespeed);
	cub->dir_y = cub->olddir_x * sin(cub->rotatespeed) +
	cub->dir_y * cos(cub->rotatespeed);
	cub->oldplane_x = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(cub->rotatespeed) -
	cub->plane_y * sin(cub->rotatespeed);
	cub->plane_y = cub->oldplane_x * sin(cub->rotatespeed) +
	cub->plane_y * cos(cub->rotatespeed);
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
