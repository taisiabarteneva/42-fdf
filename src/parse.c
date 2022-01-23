/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:53 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/23 17:02:17 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_height(t_fdf **fdf)
{
	int		height;
	char	*line;
	char	*tmp;
	int		fd;

	height = 0;
	fd = open((*fdf)->file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	get_next_line(fd, 1);
	line = get_next_line(fd, 0);
	while (line)
	{
		height++;
		tmp = line;
		line = get_next_line(fd, 0);
		free(tmp);
	}
	free(line);
	(*fdf)->height = height;
	close(fd);
}

void	calc_width(t_fdf **fdf)
{
	char	*line;
	int		fd;

	fd = open((*fdf)->file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	get_next_line(fd, 1);
	line = get_next_line(fd, 0);
	(*fdf)->width = ft_word_counter_sep(line, ' ');
	map_is_incorrent(fdf, fd);
	free(line);
	close(fd);
}

void	create(t_fdf **fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	calc_height(fdf);
	calc_width(fdf);
	(*fdf)->matrix = (t_elem **)malloc(sizeof(t_elem *) * (*fdf)->height);
	if (!(*fdf)->matrix)
	{
		ft_putendl_fd("Error: malloc\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	while (i < (*fdf)->height)
	{
		j = 0;
		(*fdf)->matrix[i] = (t_elem *)malloc(sizeof(t_elem) * ((*fdf)->width));
		if (!((*fdf)->matrix[i]))
			free_map(*fdf, 1);
		i++;
	}
}

void	fill(t_elem *row, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split((const char *)line, ' ');
	i = 0;
	while (nums[i])
	{	
		row[i].z = ft_atoi(nums[i]);
		row[i].color = COLOR;
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	parse(t_fdf **fdf)
{
	char	*line;
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	fd = open((*fdf)->file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	create(fdf);
	get_next_line(fd, 1);
	line = get_next_line(fd, 0);
	while (line && i < (*fdf)->height)
	{
		fill((*fdf)->matrix[i], line);
		i++;
		tmp = line;
		line = get_next_line(fd, 0);
		free(tmp);
	}
	free(line);
	close(fd);
}
