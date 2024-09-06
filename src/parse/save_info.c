/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:39:45 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/06 12:59:04 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char **save_map_rm_elements(t_struct *game, char **content2d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		content2d = arr_pop(content2d, 0);
		if (!content2d)
		{
			free(game->content);
			free_elements(game->element);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (content2d);
}
// handle strdup if it fails
static void save_elements(t_struct *game, char **content2d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(content2d[i], "NO ", 3))
			game->element.north = ft_strdup(content2d[i] + 3);
		else if (!ft_strncmp(content2d[i], "SO ", 3))
			game->element.south = ft_strdup(content2d[i] + 3);
		else if (!ft_strncmp(content2d[i], "WE ", 3))
			game->element.west = ft_strdup(content2d[i] + 3);
		else if (!ft_strncmp(content2d[i], "EA ", 3))
			game->element.east = ft_strdup(content2d[i] + 2);
		else if (!ft_strncmp(content2d[i], "F ", 2))
			game->element.floor = ft_strdup(content2d[i] + 2);
		else if (!ft_strncmp(content2d[i], "C ", 2))
			game->element.ceiling = ft_strdup(content2d[i] + 2);
		i++;
	}
}

void	save_info(t_struct *game, char **content2d)
{
	save_elements(game, content2d);
	game->map = save_map_rm_elements(game, content2d);
	// check elements(game->element);
}
