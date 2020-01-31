/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaastinb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:07:30 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/31 19:45:14 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void		principal2(char **argv, t_cub *cub)
{
	int		fd;
	char	*line;

	line = malloc(sizeof(char *));
	fd = open(*argv, O_RDONLY);
	if (cub3d(cub) != 1)
		ft_error();
	if (ft_get_spec(cub, fd) == 0)
		ft_error();
	if (!(cub->zbuffer = malloc(sizeof(double) * cub->width)))
		ft_error();
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr,
	cub->width, cub->height, "mlx42");
	load_cubs(cub);
	ft_loop(cub);
	ft_screenshot(cub);
	exit(0);
}
