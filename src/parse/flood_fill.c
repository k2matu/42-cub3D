/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:33:29 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/01 11:43:13 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	flood_fill(char **map, int x, int y, int row)
{
	if (y < 0 || y >= row || x < 0 || x >= (int)ft_strlen(map[y]))
		return ;
	if (!map[y][x] || map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, row);
	flood_fill(map, x - 1, y, row);
	flood_fill(map, x, y + 1, row);
	flood_fill(map, x, y - 1, row);
	return ;
}
