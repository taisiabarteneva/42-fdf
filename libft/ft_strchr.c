/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 09:46:30 by wurrigon          #+#    #+#             */
/*   Updated: 2021/10/15 10:10:01 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (s[i] != '\0')
		i++;
	i++;
	while (tmp < i)
	{
		if ((char) c == s[tmp])
			return ((char *) &s[tmp]);
		tmp++;
	}
	return (NULL);
}

// int main()
// {
//     const char str[20] = "234567";
//     char *p;
//     char *l;
//     const char ch = '5';
//     p = ft_strchr(str, ch);
//     l = ft_strchr(str, ch);
//     printf("%s\n", p);
//     printf("%s\n", l);
// }
