/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gmaeover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:14:08 by adrian            #+#    #+#             */
/*   Updated: 2020/01/28 16:26:58 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	game_over(t_cub *cub)
{
	int x;
	int y;
	int	k;

	x = -1;
	while (++x < cub->width)
	{
		y = 0;
		while (y < cub->height / 2)
		{
			ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
			&cub->tex[10].data[y % 512 * cub->tex[10].size_line +
			x % 512 * cub->tex[10].bpp / 8], sizeof(int));
			y++;
		}
		k = 0;
		while (y < cub->height)
		{
			ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
			&cub->tex[10].data[k % 512 * cub->tex[10].size_line +
			x % 512 * cub->tex[10].bpp / 8], sizeof(int));
			y++;
			k++;
		}
	}
}
