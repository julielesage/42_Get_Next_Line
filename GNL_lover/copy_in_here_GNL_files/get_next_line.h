/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:21:52 by jlesage           #+#    #+#             */
/*   Updated: 2019/12/16 11:59:50 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		ft_strlen(char *str);
char		*ft_strndup(char *s1, int n);
char		*ft_strchr(char *tmp, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_hasnewline(char *left, char **line, int ret);
int			get_next_line(int fd, char **line);

#endif
