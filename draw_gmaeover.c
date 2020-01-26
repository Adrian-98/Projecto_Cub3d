/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gmaeover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:14:08 by adrian            #+#    #+#             */
/*   Updated: 2020/01/26 14:49:06 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	game_over(t_cub *cub)
{
	int x;
	int y;
	
	x = 0;
	while (x < cub->width)
	{
		y = 0;
		while (y < cub->height - 100)
		{
			ft_memcpy(cub->data + 4 * cub->width * y + x * 4,
				&cub->tex[10].data[y * cub->tex[10].size_line +
				x  * cub->tex[10].bpp / 8], sizeof(int));
			y++;
		}
		x++;
	}
}