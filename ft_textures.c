/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:15:21 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/25 20:02:21 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	setup_shotgun(t_cub *cub)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	cub->tex[15].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/gun.xpm", &a, &b);
	cub->tex[15].data = mlx_get_data_addr(cub->tex[15].img, &cub->tex[15].bpp,
			&cub->tex[15].size_line, &cub->tex[15].endian);
	cub->tex[16].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/gun2.xpm", &a, &b);
	cub->tex[16].data = mlx_get_data_addr(cub->tex[16].img, &cub->tex[16].bpp,
			&cub->tex[16].size_line, &cub->tex[16].endian);
	cub->tex[17].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/gun3.xpm", &a, &b);
	cub->tex[17].data = mlx_get_data_addr(cub->tex[17].img, &cub->tex[17].bpp,
			&cub->tex[17].size_line, &cub->tex[17].endian);
	cub->tex[18].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/gun4.xpm", &a, &b);
	cub->tex[18].data = mlx_get_data_addr(cub->tex[18].img, &cub->tex[18].bpp,
			&cub->tex[18].size_line, &cub->tex[18].endian);
	cub->tex[19].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/gun5.xpm", &a, &b);
	cub->tex[19].data = mlx_get_data_addr(cub->tex[19].img, &cub->tex[19].bpp,
			&cub->tex[19].size_line, &cub->tex[19].endian);
}

static void	load3(t_cub *cub)
{
	int a;
	int b;

	a = 512;
	b = 512;
	cub->tex[6].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/sky2.xpm", &a, &b);
	cub->tex[6].data = mlx_get_data_addr(cub->tex[6].img, &cub->tex[6].bpp,
			&cub->tex[6].size_line, &cub->tex[6].endian);
	cub->tex[8].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/sand.xpm", &a, &b);
	cub->tex[8].data = mlx_get_data_addr(cub->tex[8].img, &cub->tex[8].bpp,
			&cub->tex[8].size_line, &cub->tex[8].endian);
	cub->tex[9].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/cristal.xpm", &a, &b);
	cub->tex[9].data = mlx_get_data_addr(cub->tex[9].img, &cub->tex[9].bpp,
			&cub->tex[9].size_line, &cub->tex[9].endian);
	cub->tex[21].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/lava.xpm", &a, &b);
	cub->tex[21].data = mlx_get_data_addr(cub->tex[9].img, &cub->tex[9].bpp,
			&cub->tex[9].size_line, &cub->tex[9].endian);
	setup_shotgun(cub);
}

static void	load2(t_cub *cub)
{
	int a;
	int b;

	a = 64;
	b = 64;
	cub->tex[3].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/redbrick.xpm", &a, &b);
	cub->tex[3].data = mlx_get_data_addr(cub->tex[3].img, &cub->tex[3].bpp,
			&cub->tex[3].size_line, &cub->tex[3].endian);
	cub->tex[4].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/stone.xpm", &a, &b);
	cub->tex[4].data = mlx_get_data_addr(cub->tex[4].img, &cub->tex[4].bpp,
			&cub->tex[4].size_line, &cub->tex[4].endian);
	cub->tex[5].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/sand.xpm", &a, &b);
	cub->tex[5].data = mlx_get_data_addr(cub->tex[5].img, &cub->tex[5].bpp,
	&cub->tex[5].size_line, &cub->tex[5].endian);
	load3(cub);
	cub->tex[20].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/skeleton.xpm", &a, &b);
	cub->tex[20].data = mlx_get_data_addr(cub->tex[20].img, &cub->tex[20].bpp,
			&cub->tex[20].size_line, &cub->tex[20].endian);
}

void		load_cubs(t_cub *cub)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	cub->tex[7].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/wood.xpm", &a, &b);
	cub->tex[7].data = mlx_get_data_addr(cub->tex[7].img, &cub->tex[7].bpp,
			&cub->tex[7].size_line, &cub->tex[7].endian);
	cub->tex[1].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/redbrick.xpm", &a, &b);
	cub->tex[1].data = mlx_get_data_addr(cub->tex[1].img, &cub->tex[1].bpp,
			&cub->tex[1].size_line, &cub->tex[1].endian);
	cub->tex[2].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"textures/mossy.xpm", &a, &b);
	cub->tex[2].data = mlx_get_data_addr(cub->tex[2].img, &cub->tex[2].bpp,
			&cub->tex[2].size_line, &cub->tex[2].endian);
	load2(cub);
}
