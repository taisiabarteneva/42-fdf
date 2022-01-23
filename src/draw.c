/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:17 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/23 14:34:29 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move(t_coord *c, t_fdf *fdf)
{
	int	z;
	int	z1;

	z = fdf->matrix[(int)c->cur_y][(int)c->cur_x].z;
	z1 = fdf->matrix[(int)c->dst_y][(int)c->dst_x].z;
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
		if ((int)c->cur_x < WIDTH
			&& (int)c->cur_y < HEIGHT
			&& (int)c->cur_x >= 0
			&& (int)c->cur_y >= 0)
			my_mlx_pixel_put(fdf->im, (int)c->cur_x, (int)c->cur_y, color);
		c->cur_x += dx;
		c->cur_y += dy;
	}
}

void	draw(t_fdf **fdf)
{
	int	x;
	int	y;

	y = 0;
	ft_memset((int *)(*fdf)->im->addr, BG_COLOR,
		WIDTH * HEIGHT * ((*fdf)->im->bpp / 8));
	while (y < (*fdf)->height)
	{
		x = 0;
		while (x < (*fdf)->width)
		{
			fill_coord(fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((*fdf)->mlx, (*fdf)->win, (*fdf)->im->ptr, 0, 0);
}
