/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:59:46 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/26 14:17:34 by adrian           ###   ########.fr       */
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
# include <stdlib.h>

# define texHeight 64
# define texWidth 64
# define WINX 900
# define WINY 700
#define NUMSPRITES 19

typedef struct				s_player
{
	double					life;
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
	char	*data;
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

	t_player	player;

	int		*zbuffer;
	int			lenline;
	
	double		inv_det;
	double		transform_x;
	double		transform_y;
	double		sprite_x;
	double		sprite_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			sprite_hit;
	int			sprite_posx;
	int			sprite_posy;
	
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		olddir_x;
	double		olddir_y;
	double		plane_x;
	double		plane_y;
	double		oldplane_x;
	double		camera_x;
	double		camera_y;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	double		rotatespeed;
	int			drawstart;
	int			drawend;
	double		movespeed;
	
	int			width;
	int			height;
	int			sky_color;
	int			wall_color;
	int			floor_color;
	int			lineHeight;
	int			map_x;
	int			map_y;
	int			hit;
	int			step_x;
	int			step_y;
	int			side;
	int			matrix[100][100];

	int			walk_front;
	int			walk_back;
	int			walk_left;
	int			walk_right;
	int			rotate_left;
	int			rotate_right;
	
	
	int			tex_x;
	int			tex_y;
	double		wall_x;
	int			id;
	t_texture	tex[25];

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
void		principal(char **argv, t_cub *cub);
void    	ft_error(void);
void		ft_walk_right(t_cub *cub);
void		ft_walk_left(t_cub *cub);
void		ft_screenshot(t_cub *cub);
void		principal2(char **argv, t_cub *cub);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			cub3d(t_cub *cub);
void		draw_sprites(t_cub *cub);
void		kill(t_cub *cub);
void		game_over(t_cub *cub);

# endif