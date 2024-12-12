/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:59:46 by glopez-a          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/25 13:47:32 by amunoz-p         ###   ########.fr       */
=======
/*   Updated: 2020/01/19 20:38:39 by adrian           ###   ########.fr       */
>>>>>>> c3041d79049f1426fdcf9c91275b94d12f0e9ee9
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H
# include "mlx.h"
# include "unistd.h"
# include "fcntl.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define DIR_X 0
# define DIR_Y 0
# define PLAN_X 0
# define PLAN_Y 0
# define X 1920

# define Y 1080
# define texHeight 64
# define texWidth 64
<<<<<<< HEAD
# define ROTATION_COEFF (float)M_PI / 1920 * 90 / 4
=======
# define WINX 1920
# define WINY 1080
>>>>>>> c3041d79049f1426fdcf9c91275b94d12f0e9ee9

typedef struct	s_texture
{
	void	*img;
	void	*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_texture;


typedef struct	s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	double		test;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		oldDirX;
	double		oldDirY;
	double		planeX;
	double		planeY;
	double		oldPlaneX;
	double		cameraX;
	double		cameraY;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		raydirX;
	double		raydirY;
	double		perpWalldist;
	double		rotatespeed;
	int			drawStart;
	int			drawEnd;
	double		movespeed;
	double		rotY;
	int			width;
	int			height;
	int			sky_color;
	int			wall_color;
	int			floor_color;
	int			lineHeight;
	int			mapX;
	int			mapY;
	int			hit;
	int			stepX;
	int			stepY;
	int			side;
	int			matrix[100][100];

	int			walk_front;
	int			walk_back;
	int			walk_left;
	int			walk_right;
	int			rotate_left;
	int			rotate_right;
	
	
	int			texX;
	int			texY;
	double		wallX;
	int			id;
	t_texture	tex[10];

	int			jump;
	int			crouch;
}				t_cub;



size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strcat(char *dst, char *src);
char		*ft_strcpy(char *dst, char *src);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		load_cubs(t_cub *cub);
void		ft_crouch_jump(t_cub *cub);
void		ft_create_matrix(int fd, char *line, t_cub *cub);
void		ft_dir(t_cub *cub, char c);
int			ft_loop(t_cub *cub);
void		init_values(t_cub *cub, int x);
void		next_step(t_cub *cub);
void		ft_movement(t_cub *cub);
int			key_press(int keycode, t_cub *cub);
int			key_realese(int keycode, t_cub *cub);
void		put_id(t_cub *cub);
void		ft_verLine(int x, int y, t_cub *cub);
void		draw_sky(t_cub *cub);

# endif