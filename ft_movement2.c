/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:20:05 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/24 20:20:28 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_walk_left(t_cub *cub)
{
	if (cub->matrix[(int)(cub->posX - cub->dirY *
	cub->movespeed)][(int)cub->posY] == 0)
		cub->posX = cub->posX - cub->dirY * cub->movespeed;
	if (cub->matrix[(int)cub->posX][(int)(cub->posY +
	cub->dirX * cub->movespeed)] == 0)
		cub->posY = cub->posY + cub->dirX * cub->movespeed;
}

void	ft_walk_right(t_cub *cub)
{
	if (cub->matrix[(int)(cub->posX + cub->dirY *
	cub->movespeed)][(int)cub->posY] == 0)
		cub->posX = cub->posX + cub->dirY * cub->movespeed;
	if (cub->matrix[(int)cub->posX][(int)(cub->posY -
	cub->dirX * cub->movespeed)] == 0)
		cub->posY = cub->posY - cub->dirX * cub->movespeed;
}
