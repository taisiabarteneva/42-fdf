/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:17 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/20 19:04:06 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move(t_coord *c, t_fdf *fdf)
{
	int	z;
	int	z1;

	z = fdf->matrix[(int)c->cur_y][(int)c->cur_x].z * fdf->data->incr;
	z1 = fdf->matrix[(int)c->dst_y][(int)c->dst_x].z * fdf->data->incr;
	zoom(c, fdf);
	if (fdf->data->proj == ISOMETRIC)
	{
		isometric(&(c->cur_x), &(c->cur_y), z, fdf);
		isometric(&(c->dst_x), &(c->dst_y), z1, fdf);
	}
	shift(c, fdf);
}

void	line_draw(t_coord *c, t_fdf *fdf)
{
	float	dx;
	float	dy;
	float	max;
	int		color;

	color = fdf->matrix[(int)c->cur_y][(int)c->cur_x].color;
	move(c, fdf);
	dx = c->dst_x - c->cur_x;
	dy = c->dst_y - c->cur_y;
	max = ft_max(dx, dy);
	dx /= max;
	dy /= max;
	while ((int)(c->dst_x - c->cur_x) || (int)(c->dst_y - c->cur_y))
	{
		if ((int)c->cur_x < WIDTH - 1
			&& (int)c->cur_y < HEIGHT - 1
			&& (int)c->cur_x >= 0
			&& (int)c->cur_y >= 0)
			my_mlx_pixel_put(fdf->im, (int)c->cur_x, (int)c->cur_y, color);
		c->cur_x += dx;
		c->cur_y += dy;
	}
}

static void	reset_background(t_fdf **fdf)
{
	int		*img;
	int		i;

	ft_bzero((*fdf)->im->addr, WIDTH * HEIGHT * ((*fdf)->im->bpp / 8));
	img = (int *)(*fdf)->im->addr;
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		img[i] = 0x000000;
		i++;
	}
}

void	draw(t_fdf **fdf)
{
	int	x;
	int	y;

	y = 0;
	reset_background(fdf);
	while (y < (*fdf)->height)
	{
		x = 0;
		while (x < (*fdf)->width)
		{
			fill_coord(&(*fdf)->c, x, y, fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((*fdf)->mlx, (*fdf)->win, (*fdf)->im->ptr, 0, 0);
}
