/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:48 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/19 23:47:50 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift(t_coord *c, t_fdf *fdf)
{
	c->cur_x += fdf->data->x_shift;
	c->cur_y += fdf->data->y_shift;
	c->dst_x += fdf->data->x_shift;
	c->dst_y += fdf->data->y_shift;
}

void	zoom(t_coord *c, t_fdf *fdf)
{
	c->cur_x *= fdf->data->zoom;
	c->cur_y *= fdf->data->zoom;
	c->dst_x *= fdf->data->zoom;
	c->dst_y *= fdf->data->zoom;
}

void	isometric(float *x, float *y, int z, t_fdf *fdf)
{
	*x = (*x - *y) * cos(fdf->data->angl);
	*y = (*x + *y) * sin(fdf->data->angl) - z;
}
