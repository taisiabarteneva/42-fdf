/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter_sep.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:36:00 by wurrigon         #+#    #+#             */
/*   Updated: 2022/01/19 23:36:02 by wurrigon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_counter_sep(char const *str, char sep)
{
	size_t	i;
	size_t	count;
	size_t	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != sep && str[i] != '\n' && flag == 0)
		{
			flag = 1;
			count += 1;
		}
		else if (str[i] == sep && flag == 1)
			flag = 0;
		i++;
	}
	return (count);
}
