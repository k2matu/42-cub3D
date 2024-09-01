/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:25:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/08/30 09:23:45 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_map(int argc, char **argv, t_struct *game)
{
	if (argc != 2 || ft_strrncmp(argv[1], ".cub", 4) != 0 || ft_strlen(argv[1]) < 5)
	{
		ft_putendl_fd(INVALID_MAP_EXTENSTION, 2);
		exit(1);
	}
	game->map_2d = read_to_map(argv[1]);
	ft_print_two_d_arr(game->map_2d);
	// free map_2d;
}
