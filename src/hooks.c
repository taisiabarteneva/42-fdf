/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:30 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/23 17:05:29 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_shift(int code, t_fdf *fdf)
{
	if (fdf->height < MAX_HEIGHT)
	{
		if (code == KEY_UP)
			fdf->data->y_shift -= 10;
		else if (code == KEY_DOWN)
			fdf->data->y_shift += 10;
		else if (code == KEY_LEFT)
			fdf->data->x_shift -= 10;
		else
			fdf->data->x_shift += 10;
	}
	else
	{
		if (code == KEY_UP)
			fdf->data->y_shift += 10;
		else if (code == KEY_DOWN)
			fdf->data->y_shift -= 10;
		else if (code == KEY_LEFT)
			fdf->data->x_shift += 10;
		else
			fdf->data->x_shift -= 10;
	}
	draw(&fdf);
}

void	change_zoom(int code, t_fdf *fdf)
{
	if (code == ZOOM_IN && fdf->data->zoom > 2)
		fdf->data->zoom -= 1;
	else if (code == ZOOM_OUT && fdf->data->zoom < 50)
		fdf->data->zoom += 1;
	draw(&fdf);
}

void	change_projection(t_fdf *fdf)
{
	if (fdf->data->proj == ISOMETRIC)
		fdf->data->proj = PARALLEL;
	else
		fdf->data->proj = ISOMETRIC;
	draw(&fdf);
}

int	key_hooks(int code, t_fdf *fdf)
{
	if (code == ESC)
		exit(EXIT_SUCCESS);
	else if (code >= KEY_LEFT && code <= KEY_UP)
	{
		change_shift(code, fdf);
	}
	else if (code == ZOOM_IN || code == ZOOM_OUT)
	{
		change_zoom(code, fdf);
	}
	else if (code == PROJ)
	{
		change_projection(fdf);
	}
	return (0);
}
