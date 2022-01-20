/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:53 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/20 21:16:34 by wurrigon         ###   ########.fr       */
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
	get_next_line(fd, 1);
	line = get_next_line(fd, 0);
	while (line)
	{
		height++;
		tmp = line;
		line = get_next_line(fd, 0);
		free(tmp);
		tmp = NULL;
	}
	free(line);
	line = NULL;
	(*fdf)->height = height;
	close(fd);
}

void	calc_width(t_fdf **fdf)
{
	char	*line;
	int		fd;

	fd = open((*fdf)->file, O_RDONLY);
	get_next_line(fd, 1);
	line = get_next_line(fd, 0);
	(*fdf)->width = ft_word_counter_sep(line, ' ');
	map_is_incorrent(fdf, fd);
	free(line);
	line = NULL;
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
		free_map(*fdf, 1);
	while (i < (*fdf)->height)
	{
		j = 0;
		(*fdf)->matrix[i] = (t_elem *)malloc(sizeof(t_elem) * ((*fdf)->width));
		if (!((*fdf)->matrix[i]))
			free_map(*fdf, 1);
		while (j < (*fdf)->width)
		{
			(*fdf)->matrix[i][j].z = 0;
			(*fdf)->matrix[i][j].color = 0xFFFFFF;
			j++;
		}
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
	nums = NULL;
}

void	parse(t_fdf **fdf)
{
	char	*line;
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	fd = open((*fdf)->file, O_RDONLY);
	create(fdf);
	get_next_line(fd, 1);
	line = get_next_line(fd, 0);
	while (line && (*fdf)->matrix[i])
	{
		fill((*fdf)->matrix[i], line);
		i++;
		tmp = line;
		line = get_next_line(fd, 0);
		free(tmp);
		tmp = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
}
