/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1019/11/11 17:51:10 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/29 15:49:56 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int			cub3d(t_cub *cub)
{
	cub->width = 1000;
	cub->height = 700;
	cub->movespeed = 0.08;
	cub->rotatespeed = 0.05;
	cub->crouch = 0;
	cub->shot = 0;
	cub->sprite_count = 0;
	cub->lenline = -1;
	cub->player.shooting = 0;
	cub->player.fr = 17;
	cub->player.name = "THE KING!";
	cub->player.life = 100;
	cub->player.bullets = 8;
	cub->player.reload = 0;
	cub->player.x_pos += 0.5;
	cub->player.y_pos += 0.5;
	cub->sprite_hit = 0;
	cub->sprite_on = 0;
	cub->floor_color = 0xFFFFFF;
	if (!(cub->zbuffer = malloc(sizeof(double) * cub->width)))
		return (0);
	//system("afplay ./sounds/sound3.mp3& 2&>/dev/null >/dev/null");

	return (1);
}

int			mouse_functions(int x, int y, t_cub *cub)
{
	cub->dir_x = sin((x * 720 / cub->width) * M_PI / 180);
	cub->dir_y = cos((x * 720 / cub->width) * M_PI / 180);
	cub->plane_x = 0.66 * cub->dir_y;
	cub->plane_y = -0.66 * cub->dir_x;
	(void)y;

	return (0);
}

void		principal(char **argv, t_cub *cub)
{
	int		fd;
	char	*line;

	line = malloc(sizeof(char *));
	fd = open(*argv, O_RDONLY);
	if (cub3d(cub) != 1)
		ft_error();
	ft_read_resolution(fd, line, cub);

	ft_create_matrix(fd, line, cub);
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr,
	cub->width, cub->height, "mlx42");
	load_cubs(cub);
	mlx_hook(cub->win_ptr, 2, 0, key_press, cub);
	mlx_hook(cub->win_ptr, 3, 0, key_realese, cub);
	mlx_hook(cub->win_ptr, 17, 0, close_window, cub);
	mlx_hook(cub->win_ptr, 6, 0, mouse_functions, cub);
	mlx_loop_hook(cub->mlx_ptr, ft_loop, cub);
	mlx_loop(cub->mlx_ptr);
	free(cub);
	free(cub->zbuffer);
	free(line);
}

int			main(int argc, char **argv)
{
	t_cub	*cub;

	if (!(cub = malloc(sizeof(t_cub))))
		ft_error();
	if (argc == 2)
		principal(&argv[1], cub);
	else if (argc == 3 && ft_strncmp("--save", argv[2], 6) == 0)
	{
		principal2(&argv[1], cub);
	}
	else
		ft_error();
	return (0);
}
