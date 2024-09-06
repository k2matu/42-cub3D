/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:39:45 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/06 15:06:13 by kmatjuhi         ###   ########.fr       */
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
			free_all(game, content2d);
		i++;
	}
	return (content2d);
}

static void save_element(char **dst, const char *src, t_struct *game, char **content2d)
{
    *dst = ft_strdup(src);
    if (!*dst)
        free_all(game, content2d);
}

static void save_elements(t_struct *game, char **content2d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(content2d[i], "NO ", 3))
			save_element(&game->element.north, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "SO ", 3))
			save_element(&game->element.south, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "WE ", 3))
			save_element(&game->element.west, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "EA ", 3))
			save_element(&game->element.east, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "F ", 2))
			save_element(&game->element.floor, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "C ", 2))
			save_element(&game->element.ceiling, content2d[i] + 3, game, content2d);
		i++;
	}
}

void	save_info(t_struct *game, char **content2d)
{
	save_elements(game, content2d);
	game->map = save_map_rm_elements(game, content2d);
	// check elements(game->element);
}
