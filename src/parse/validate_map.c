/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:38:57 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/09 12:23:18 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int save_player_pos(t_struct *game, char *map, int row, int player_count)
{
	int	col;

	col = 0;
    while (map[col])
    {
        if (map[col] == 'N' || map[col] == 'S' || map[col] == 'E' || map[col] == 'W')
        {
            player_count++;
            game->player.pos_y = row;
            game->player.pos_x = col;
        }
        col++;
    }
    return (player_count);
}

static bool surrounded_by_walls(char **map)
{
    
}

void validate_map(t_struct *game, char **map)
{
    ft_print_arr(map);
    int row;
    int player_count;

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
    if (!surrounded_by_walls(map));
        clean_exit(game, ERR_MAP_INVALID, map);
}
