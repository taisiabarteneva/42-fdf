/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:18:10 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/21 15:24:04 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
