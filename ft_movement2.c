/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:20:05 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/25 12:44:29 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_walk_left(t_cub *cub)
{
	if (cub->matrix[(int)(cub->pos_x - cub->dir_y *
	cub->movespeed)][(int)cub->pos_y] == 0)
		cub->pos_x = cub->pos_x - cub->dir_y * cub->movespeed;
	if (cub->matrix[(int)cub->pos_x][(int)(cub->pos_y +
	cub->dir_x * cub->movespeed)] == 0)
		cub->pos_y = cub->pos_y + cub->dir_x * cub->movespeed;
}

void	ft_walk_right(t_cub *cub)
{
	if (cub->matrix[(int)(cub->pos_x + cub->dir_y *
	cub->movespeed)][(int)cub->pos_y] == 0)
		cub->pos_x = cub->pos_x + cub->dir_y * cub->movespeed;
	if (cub->matrix[(int)cub->pos_x][(int)(cub->pos_y -
	cub->dir_x * cub->movespeed)] == 0)
		cub->pos_y = cub->pos_y - cub->dir_x * cub->movespeed;
}
