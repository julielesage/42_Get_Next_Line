/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 00:14:34 by jlesage           #+#    #+#             */
/*   Updated: 2019/12/16 13:43:18 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ret;

	if (ac == 1)
		return (-1);
	line = NULL;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("line : |%s| ret : %d\n", line, ret);
		free(line);
		line = NULL;
	}
	printf("line : |%s| ret : %d\n", line, ret);
	free(line);
	close(fd);
/*	while (1)
	{
	}*/
	return (0);
}
