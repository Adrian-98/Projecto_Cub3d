/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:41:55 by adrian            #+#    #+#             */
/*   Updated: 2020/01/31 17:27:46 by amunoz-p         ###   ########.fr       */
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
