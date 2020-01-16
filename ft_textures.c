/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:15:21 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/15 11:51:15 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	load_cubs(t_cub *cub)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	printf("holaaa\n");
	cub->tex[0].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/wood.xpm", &a, &b);
	printf("adioooos\n");
	cub->tex[0].data = mlx_get_data_addr(cub->tex[0].img, &cub->tex[0].bpp,
			&cub->tex[0].size_line, &cub->tex[0].endian);
    printf("valor de bpp%i\n%i\n%i\n", cub->tex[0].bpp, cub->tex[0].size_line, cub->tex[0].endian);
	cub->tex[1].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/wood.xpm", &a, &b);
	cub->tex[1].data = mlx_get_data_addr(cub->tex[1].img, &cub->tex[1].bpp,
			&cub->tex[1].size_line, &cub->tex[1].endian);
	cub->tex[2].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/mossy.xpm", &a, &b);
	cub->tex[2].data = mlx_get_data_addr(cub->tex[2].img, &cub->tex[2].bpp,
			&cub->tex[2].size_line, &cub->tex[2].endian);
	cub->tex[3].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/redbrick.xpm", &a, &b);
	cub->tex[3].data = mlx_get_data_addr(cub->tex[3].img, &cub->tex[3].bpp,
			&cub->tex[3].size_line, &cub->tex[3].endian);
	cub->tex[4].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/wood.xpm", &a, &b);
	cub->tex[4].data = mlx_get_data_addr(cub->tex[4].img, &cub->tex[4].bpp,
			&cub->tex[4].size_line, &cub->tex[4].endian);
}