/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:44:49 by wurrigon          #+#    #+#             */
/*   Updated: 2021/10/15 09:40:50 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	size_t			i;
	char			*tmp;

	ch = (unsigned char) c;
	i = 0;
	tmp = (char *)b;
	while (i < len)
	{
		*(tmp + i) = ch;
		i++;
	}
	return (b);
}

// int main(void)
// {
//     char str[50] = "Where is my mind? It\'s far away";
//     ft_memset(str, '*', 5);
//     printf("%s\n", str);
// }
