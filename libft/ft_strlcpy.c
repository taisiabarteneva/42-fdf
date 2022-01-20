/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sexysushi <sexysushi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 09:59:04 by wurrigon          #+#    #+#             */
/*   Updated: 2022/01/19 23:33:36 by sexysushi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize > 0)
	{
		while (*(src + i) != '\0')
		{
			if (i == dstsize - 1)
				break ;
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	while (*(src + j) != '\0')
		j++;
	return (j);
}
