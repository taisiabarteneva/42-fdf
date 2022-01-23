/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:18:10 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/23 17:04:34 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	check(ac, av);
	fdf = init_fdf(av[1]);
	parse(&fdf);
	draw(&fdf);
	mlx_hook(fdf->win, KEY_P, 1L << 0, key_hooks, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
