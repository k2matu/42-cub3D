/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:38:57 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/09 11:25:15 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	check_components(char **map, t_struct *game)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	j = 0;
// 	while (map[++i] != NULL)
// 	{
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'C')
// 				game->comp.collectible++;
// 			else if (map[i][j] == 'E')
// 				game->comp.exit++;
// 			else if (map[i][j] == 'P')
// 				game->comp.player++;
// 			j++;
// 		}
// 		j = 0;
// 	}
// 	if (game->comp.collectible < 1 || game->comp.player != 1 \
// 	|| game->comp.exit != 1)
// 		ft_error(NULL, "Map must contain 1 exit, \
// 		1 startposition & collectible", map);
// }

void validate_map_content(t_struct *game, char **map)
{
    ft_print_arr(map);
    int row;

    row = 0;
    while (map[row])
    {
        if (ft_match(map[row], "01NSEW ") != 1)
		    clean_exit(game, ERR_MAP_CHAR, map);
        row++;
    }
}