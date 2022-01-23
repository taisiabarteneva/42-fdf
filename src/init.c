/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:36 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/23 16:30:02 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_im(t_img **im, void **mlx)
{
	(*im) = (t_img *)malloc(sizeof(t_img));
	if (!(*im))
	{
		perror("Memory allocation failed ");
		exit(EXIT_FAILURE);
	}
	(*im)->ptr = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!(*im)->ptr)
	{
		perror("Unable to create an image ");
		exit(EXIT_FAILURE);
	}
	(*im)->addr = mlx_get_data_addr(((*im)->ptr), &((*im)->bpp),
			&((*im)->line_len), &((*im)->endian));
	if (!((*im)->addr))
	{
		perror("Unable to init an image ");
		exit(EXIT_FAILURE);
	}
}

void	init_data(t_fdf *fdf)
{
	fdf->data = (t_params *)malloc(sizeof(t_params));
	if (!fdf->data)
	{
		perror("Memory allocation failed ");
		exit(EXIT_FAILURE);
	}
	fdf->data->x_shift = X_SHIFT;
	fdf->data->y_shift = Y_SHIFT;
	fdf->data->zoom = ZOOM;
	fdf->data->incr = INCREASE;
	fdf->data->angl = ANGLE;
	fdf->data->proj = ISOMETRIC;
}

t_fdf	*init_fdf(char *file)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
	{
		perror("Memory allocation failed ");
		exit(EXIT_FAILURE);
	}
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		perror("Unable to init mlx ");
		exit(EXIT_FAILURE);
	}
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT - 30, "fdf");
	if (!fdf->win)
	{
		perror("Unable to create a window ");
		exit(EXIT_FAILURE);
	}
	fdf->file = file;
	init_im(&fdf->im, &(fdf->mlx));
	init_data(fdf);
	return (fdf);
}
