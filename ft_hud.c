/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:41:55 by adrian            #+#    #+#             */
/*   Updated: 2020/01/31 19:29:28 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void		put_hud(t_cub *cub)
{
	int		i;
	char	*tmp;

	tmp = ft_itoa(cub->player.bullets);
	i = 0;
	while (i++ < cub->player.life)
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 10 + i,
			cub->height - 30, 0xFF0000, "|");
	while (i++ < 100)
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 10 + i,
			cub->height - 30, 0x808080, "|");
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->width - 30,
		cub->height - 40, 0x00000, tmp);
	mlx_string_put(cub->mlx_ptr, cub->win_ptr,
		cub->width - 30, cub->height - 40, 0x00000, " /8");
	mlx_string_put(cub->mlx_ptr, cub->win_ptr,
		cub->width / 2, cub->height / 2 + 15, 0xFFFFF, "()");
	free(tmp);
}

void			fps(t_cub *cub)
{
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, 10, 20,
	0xffffff, cub->player.name);
	put_hud(cub);
}

void			cubside(t_cub *cub)
{
	if (cub->side == 0)
		cub->perpwalldist = (cub->map_x - cub->pos_x +
		(1 - cub->step_x) / 2) / cub->raydir_x;
	else
		cub->perpwalldist = (cub->map_y - cub->pos_y +
		(1 - cub->step_y) / 2) / cub->raydir_y;
	cub->lineHeight = (int)(cub->height / cub->perpwalldist);
	cub->drawstart = -cub->lineHeight / 2 + cub->height / 2;
	if (cub->drawstart < 0)
		cub->drawstart = 0;
	cub->drawend = cub->lineHeight / 2 + cub->height / 2;
	if (cub->drawend >= cub->height)
		cub->drawend = cub->height - 1;
	if (cub->side == 0)
		cub->wall_x = cub->pos_y + cub->perpwalldist * cub->raydir_y;
	else
		cub->wall_x = cub->pos_x + cub->perpwalldist * cub->raydir_x;
}
