/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:48:03 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/20 19:04:57 by wurrigon         ###   ########.fr       */
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

void	fill_coord(t_coord **c, int x, int y, t_fdf **fdf)
{
	if (x < (*fdf)->width - 1 && x >= 0)
	{
		(*c)->start_x = x;
		(*c)->start_y = y;
		(*c)->cur_x = x;
		(*c)->cur_y = y;
		(*c)->dst_x = x + 1;
		(*c)->dst_y = y;
		line_draw(*c, *fdf);
	}
	if (y < (*fdf)->height - 1 && y >= 0)
	{
		(*c)->start_x = x;
		(*c)->start_y = y;
		(*c)->cur_x = x;
		(*c)->cur_y = y;
		(*c)->dst_x = x;
		(*c)->dst_y = y + 1;
		line_draw(*c, *fdf);
	}
}
