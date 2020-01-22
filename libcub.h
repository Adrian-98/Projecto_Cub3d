/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:59:46 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/22 15:18:21 by adrian           ###   ########.fr       */
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
# include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

# define texHeight 64
# define texWidth 64
# define WINX 1920
# define WINY 1080

typedef struct				s_sprites_work
{
	double					sp_x;
	double					sp_y;
	double					inv_det;
	double					transform_x;
	double					transform_y;
	int						sp_screen_x;
	int						vms;
	int						sp_height;
	int						draw_start_y;
	int						draw_end_y;
	int						sp_width;
	int						draw_start_x;
	int						draw_end_x;
	int						stripe;
	int						tex_x;
	int						y;
	int						d;
	int						tex_y;
	int						color;
}							t_sprites_work;

typedef struct				s_window
{
	void					*mlx;
	void					*win;
	void					*img;
	void					*img_ptr;
	int						window_width;
	int						window_height;
	int						bpp;
	int						endian;
	int						sl;
}							t_window;

typedef struct				s_sprites
{
	int						x;
	int						y;
	int						tex_index;
}							t_sprites;

typedef struct				s_player
{
	short					life;
	short					bullets;
	char					*name;
	int						shooting;
	int						fr;
	short					reload;
	int						chest_collected;
	int						chest_to_collect;
	int						ended;
	double					x_pos;
	double					y_pos;
	double					x_dir;
	double					y_dir;
}							t_player;

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

	t_sprites	*sprites;
	t_player	player;
	t_window	window;
	double		*zbuffer;
	int			lenline;
	
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
	t_texture	tex[20];

	int			shot;
	int			crouch;
}				t_cub;

void		draw_gun(t_cub *cub);
char		*ft_itoa(int n);
void		fps(t_cub *cub);
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
int			close_window(t_cub *cub);

# endif