/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:59:23 by jlesage           #+#    #+#             */
/*   Updated: 2019/12/09 17:01:13 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <ctype.h>
#include <stdlib.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*d;

	i = 0;
	d = NULL;
	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strndup(char *s1, int n)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * n + 1);
	if (copy == NULL)
		return (NULL);
	while (i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(char *str)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (str == NULL)
		count = 0;
	else
	{
		while (str[i] != '\0')
		{
			count++;
			i++;
		}
	}
	return (count);
}

char	*ft_strchr(char *left, char c)
{
	int		i;

	i = 0;
	if (left == NULL)
		return (NULL);
	while (left[i] != '\0')
	{
		if (left[i] == c)
			return (&left[i + 1]);
		else
			i++;
	}
	if (c == '\0')
		return (&left[i]);
	return (NULL);
}
