/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:51:21 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/08/30 09:26:29 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*read_file(char *str)
{
	int		fd;
	int		sz;
	char	c;
	char	*map;

	sz = 0;
	fd = safe_open(str);
	while (read(fd, &c, 1) == 1)
		sz++;
	close(fd);
	fd = safe_open(str);
	map = malloc(sizeof(char) * (sz + 1));
	if (!map)
	{
		ft_putendl_fd(MALLOC_ERR, 2);
		exit(1);
	}
	read(fd, map, sz);
	close(fd);
	map[sz] = '\0';
	return (map);
}

char	**read_to_map(char *str)
{
	char	*map_1d;
	char	**map_2d;

	map_1d = read_file(str);
	map_2d = ft_split(map_1d, '\n');
	free(map_1d);
	if (!map_2d)
	{
		ft_putendl_fd(MALLOC_ERR, 2);
		exit(1);
	}
	return (map_2d);
}
