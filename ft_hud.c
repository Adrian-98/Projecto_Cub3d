/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:41:55 by adrian            #+#    #+#             */
/*   Updated: 2020/01/26 14:18:40 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	put_hud(t_cub *cub)
{
	int	i;

	i = 0;
	while (i++ < cub->player.life)
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 10 + i,
			cub->height - 30, 0xFF0000, "|");
	while (i++ < 100)
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 10 + i,
			cub->height - 30, 0x808080, "|");
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->width - 30,
		cub->height - 40, 0x00000, ft_itoa(cub->player.bullets));
	mlx_string_put(cub->mlx_ptr, cub->win_ptr,
		cub->width - 30, cub->height - 40, 0x00000, " /8");
	mlx_string_put(cub->mlx_ptr, cub->win_ptr,
		cub->width / 2, cub->height / 2 + 15, 0xFFFFF, "()");
}

void		fps(t_cub *cub)
{
	static int		timestamp;
	static int		fps;
	static int		fps_temp;

	if (time(NULL) != timestamp)
	{
		fps_temp = fps;
		fps = 0;
		timestamp = (int)time(NULL);
	}
	else
		fps++;
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, 10, 20,
	0xffffff, cub->player.name);
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->width - 20,
		20, 0xe5e500, ft_itoa(fps_temp + 1));
	put_hud(cub);
}
