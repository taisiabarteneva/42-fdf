/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:24 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/20 18:56:55 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_fdf *fdf, int flag)
{
	int	i;

	i = 0;
	while (fdf->matrix[i])
	{
		dprintf(2, "MATRIX I %p\n", fdf->matrix[i]);
		free(fdf->matrix[i]);
		fdf->matrix[i] = NULL;
		i++;
	}
	dprintf(2, "MATRIX %p\n", fdf->matrix);
	free(fdf->matrix);
	fdf->matrix = NULL;
	if (flag > 0)
	{
		ft_putendl_fd("Error: malloc", 1);
		exit(EXIT_FAILURE);
	}
}
