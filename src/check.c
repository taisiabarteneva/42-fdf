/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:11 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/23 11:37:56 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_is_incorrent(t_fdf **fdf, int fd)
{
	int		w;
	char	*line;
	char	*tmp;

	w = 1;
	line = get_next_line(fd, 0);
	while (line)
	{	
		w = ft_word_counter_sep(line, ' ');
		if (w != (*fdf)->width)
		{
			ft_putendl_fd("Incorrect map.", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		tmp = line;
		line = get_next_line(fd, 0);
		free(tmp);
		tmp = NULL;
	}
	free(line);
	line = NULL;
}

static void	open_file(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Can't open a file ");
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp_ext(filename, "fdf") == 1)
	{
		ft_putendl_fd("Enter a file with the extension <.fdf>.", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd, 0);
	if (!line)
	{
		ft_putendl_fd("Enter non-empty file.", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	free(line);
	line = NULL;
	close(fd);
}

void	check(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Usage : ", STDOUT_FILENO);
		ft_putstr_fd(av[0], STDOUT_FILENO);
		ft_putendl_fd(" <filename>", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	open_file(av[1]);
}
