/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:48:03 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/23 13:57:41 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_max(float a, float b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		return (a);
	return (b);
}

void	fill_coord(t_fdf **fdf, int x, int y)
{
	if (x < (*fdf)->width - 1 && x >= 0)
	{
		(*fdf)->c.start_x = x;
		(*fdf)->c.start_y = y;
		(*fdf)->c.cur_x = x;
		(*fdf)->c.cur_y = y;
		(*fdf)->c.dst_x = x + 1;
		(*fdf)->c.dst_y = y;
		line_draw(&(*fdf)->c, *fdf);
	}
	if (y < (*fdf)->height - 1 && y >= 0)
	{
		(*fdf)->c.start_x = x;
		(*fdf)->c.start_y = y;
		(*fdf)->c.cur_x = x;
		(*fdf)->c.cur_y = y;
		(*fdf)->c.dst_x = x;
		(*fdf)->c.dst_y = y + 1;
		line_draw(&(*fdf)->c, *fdf);
	}
}
