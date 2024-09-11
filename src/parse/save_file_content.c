/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:51:21 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/09 14:48:23 by kmatjuhi         ###   ########.fr       */
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
	while (safe_read(fd, &c, 1, false) == 1)
		sz++;
	close(fd);
	fd = safe_open(str);
	map = malloc(sizeof(char) * (sz + 1));
	if (!map)
	{
		ft_putendl_fd(ERR_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	safe_read(fd, map, sz, true);
	close(fd);
	map[sz] = '\0';
	return (map);
}

char	**save_file_content(t_struct *game, char *str)
{
	char	**content2d;

	game->content = read_file(str);
	content2d = ft_split(game->content, '\n');
	if (!content2d)
	{
		free(game->content);
		ft_putendl_fd(ERR_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	return (content2d);
}
