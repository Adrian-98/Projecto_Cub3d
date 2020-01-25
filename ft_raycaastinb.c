/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaastinb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:07:30 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/25 15:04:00 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void		principal2(char **argv, t_cub *cub)
{
	int		fd;
	char	*line;

	line = malloc(sizeof(char *));
	fd = open(*argv, O_RDONLY);
	cub3d(cub);
	ft_create_matrix(fd, line, cub);
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr,
	cub->width, cub->height, "mlx42");
	load_cubs(cub);
	// mlx_hook(cub->win_ptr, 2, 0, key_press, cub);
	// mlx_hook(cub->win_ptr, 3, 0, key_realese, cub);
	// mlx_hook(cub->win_ptr, 17, 0, close_window, cub);
	ft_loop(cub);
	ft_screenshot(cub);
	free(cub);
	exit(0);
}
