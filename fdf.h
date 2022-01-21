/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:03 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/21 15:24:23 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* # include 	<mlx.h> */
# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

/* window */
# define HEIGHT 	800
# define WIDTH 		1000
# define MAX_HEIGHT 99

# define COLOR		0xf5f5f5
# define BG_COLOR	0x222222

/* params */
# define X_SHIFT	400
# define Y_SHIFT	300
# define ZOOM		20
# define ISOMETRIC	1
# define PARALLEL 	2
# define INCREASE	15
# define ANGLE		0.8

/* key codes */
# define ESC		53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define ZOOM_IN	27
# define ZOOM_OUT	24
# define PROJ		49

typedef struct s_params
{
	int		x_shift;
	int		y_shift;
	int		zoom;
	int		incr;
	float	angl;
	int		proj;
}				t_params;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_elem
{
	int	z;
	int	color;
}				t_elem;

typedef struct s_coord
{
	float	cur_x;
	float	cur_y;
	float	start_x;
	float	start_y;
	float	dst_x;
	float	dst_y;
}				t_coord;	

typedef struct s_fdf
{
	char		*file;
	void		*mlx;
	void		*win;
	t_img		*im;
	t_elem		**matrix;
	int			height;
	int			width;
	t_params	*data;
	t_coord		*c;
}				t_fdf;	

/* parse */
void	check(int ac, char **av);
void	map_is_incorrent(t_fdf **fdf, int fd);
void	parse(t_fdf **fdf);

/* init */
t_fdf	*init_fdf(char *file);
void	init_coord(t_coord **c);

/* color */
int		get_color(int z_val);
void	get_color_from_map(t_elem *el, char *line);

/* free */
void	free_map(t_fdf *fdf, int flag);
void	free_all(t_fdf *fdf);

/* utils */
void	fill_coord(t_coord **c, int x, int y, t_fdf **fdf);
int		ft_max(float a, float b);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

/* move */
void	shift(t_coord *c, t_fdf *fdf);
void	zoom(t_coord *c, t_fdf *fdf);
void	isometric(float *x, float *y, int z, t_fdf *fdf);

/* hooks */
int		key_hooks(int code, t_fdf *fdf);

/* draw */
void	draw(t_fdf **fdf);
void	line_draw(t_coord *c, t_fdf *fdf);

#endif