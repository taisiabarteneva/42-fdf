/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:21:06 by wurrigon          #+#    #+#             */
/*   Updated: 2021/10/26 14:28:45 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include   <unistd.h>
# include   <stdlib.h>
# include   <limits.h>

# include	"libft.h"

# define BUFFER_SIZE	100

void	ft_fill_line(char **rmd, char **line, int size);
void	ft_handle_remainder(char **rmd, char **line);
int		ft_read(int fd, char **rmd, char **buf, char **line);
char	*get_next_line(int fd, int reset);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
