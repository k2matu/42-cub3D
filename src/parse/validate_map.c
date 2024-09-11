/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:38:57 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/11 13:19:55 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	save_player_pos(t_struct *game, char *map, int row, int plr_count)
{
	int	col;

	col = 0;
	while (map[col])
	{
		if (map[col] == 'N' || map[col] == 'S' || map[col] == 'E' || \
		map[col] == 'W')
		{
			plr_count++;
			game->player.pos_y = row;
			game->player.pos_x = col;
			game->player.direction = map[col];
		}
		col++;
	}
	return (plr_count);
}

static bool	validate_row_walls(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] == 'X')
			return (false);
		i++;
	}
	return (true);
}

static bool	validate_walls(char **map, int row)
{
	int	i;
	int	len;

	i = 0;
	if (!validate_row_walls(map[0]) || !validate_row_walls(map[row]))
		return (false);
	while (i < row)
	{
		len = ft_strlen(map[i]) - 1;
		if (map[i][0] == 'X' || map[i][len] == 'X')
			return (false);
		i++;
	}
	return (true);
}

static bool	is_map_enclosed(t_struct *game, char **map, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == game->player.direction)
				flood_fill(map, j, i, row);
			j++;
		}
		j = 0;
		i++;
	}
	return (validate_walls(map, row - 1));
}

void	validate_map(t_struct *game, char **map)
{
	int		row;
	int		player_count;
	char	**map_copy;

	row = 0;
	player_count = 0;
	while (map[row])
	{
		if (!ft_match(map[row], "01NSEW "))
			clean_exit(game, ERR_MAP_CHAR, map);
		player_count = save_player_pos(game, map[row], row, player_count);
		row++;
	}
	if (player_count != 1)
		clean_exit(game, ERR_PLAYER_COUNT, map);
	map_copy = ft_arrdup(map);
	if (!map_copy)
		clean_exit(game, ERR_MALLOC, map);
	if (!is_map_enclosed(game, map_copy, row))
	{
		ft_free_arr(map_copy);
		clean_exit(game, ERR_MAP_INVALID, map);
	}
	ft_free_arr(map_copy);
}
