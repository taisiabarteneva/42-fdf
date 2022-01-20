/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:18:10 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/20 21:15:56 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_fdf *fdf)
{
	free_map(fdf, 0);
	free(fdf->im->ptr);
	free(fdf->im);
	free(fdf->c);
	free(fdf->mlx);
	free(fdf->data);
	free(fdf);
	fdf = NULL;
}

int	main(int ac, char **av)
{			
	t_fdf	*fdf;
	t_coord	*coord;

	check(ac, av);
	fdf = init_fdf(av[1]);
	parse(&fdf);
	init_coord(&coord);
	draw(&fdf);
	mlx_hook(fdf->win, 2, 0, key_hooks, fdf);
	mlx_loop(fdf->mlx);
	free_all(fdf);
	return (0);
}
