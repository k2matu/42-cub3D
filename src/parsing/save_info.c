/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:39:45 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/05 11:52:35 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	remove_saved_info(t_struct *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		game->map = arr_pop(game->map, 0);
		if (!game->map)
		{
			free_texture(game->texture);
			exit(1);
		}
		i++;
	}
}

void	save_info(t_struct *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(game->map[i], "NO ", 3))
			game->texture.north = ft_strdup(game->map[i] + 3);
		else if (!ft_strncmp(game->map[i], "SO ", 3))
			game->texture.south = ft_strdup(game->map[i] + 3);
		else if (!ft_strncmp(game->map[i], "WE ", 3))
			game->texture.west = ft_strdup(game->map[i] + 3);
		else if (!ft_strncmp(game->map[i], "EA ", 3))
			game->texture.east = ft_strdup(game->map[i] + 2);
		else if (!ft_strncmp(game->map[i], "F ", 2))
			game->texture.floor = ft_strdup(game->map[i] + 2);
		else if (!ft_strncmp(game->map[i], "C ", 2))
			game->texture.ceiling = ft_strdup(game->map[i] + 2);
		i++;
	}
	remove_saved_info(game);
}
