/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:50:13 by jlesage           #+#    #+#             */
/*   Updated: 2019/12/12 15:09:46 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_errorsofree(char *buf)
{
	free(buf);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*dst;
	size_t		i;
	size_t		j;
	size_t		totalsize;

	i = 0;
	j = 0;
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = (char *)malloc((totalsize + 1) * (sizeof(char)))))
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	if (s1 != NULL)
		free(s1);
	s2 = NULL;
	s1 = NULL;
	return (dst);
}

char	*ft_hasnewline(char *left, char **line, int ret)
{
	int		i;
	char	*dst;

	i = 0;
	dst = NULL;
	if (left != NULL)
	{
		while (left[i] != '\n' && left[i] != '\0')
			i++;
		*line = ft_strndup(left, i);
		if (ret > 0)
			dst = ft_substr(left, i + 1, (ft_strlen(left) - i));
	}
	free(left);
	return (dst);
}

int		get_next_line(int fd, char **line)
{
	static char		*left;
	char			*buf;
	int				ret;

	if (BUFFER_SIZE <= 0 || fd > 10000 || fd < 0 || !(line))
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = 1;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		while (ret > 0 && ft_strchr(left, '\n') == NULL)
		{
			if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
				return (ft_errorsofree(buf));
			buf[ret] = '\0';
			left = ft_strjoin(left, buf);
		}
		free(buf);
		left = ft_hasnewline(left, line, ret);
	}
	if (ret > 1)
		ret = 1;
	return (ret);
}
