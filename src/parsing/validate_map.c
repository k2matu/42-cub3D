/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:25:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/06 09:02:37 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture(t_texture texture)
{
	if (texture.north)
		free(texture.north);
	if (texture.south)
		free(texture.south);
	if (texture.west)
		free(texture.west);
	if (texture.east)
		free(texture.east);
	if (texture.floor)
		free(texture.floor);
	if (texture.ceiling)
		free(texture.ceiling);
}

void	validate_map(int argc, char **argv, t_struct *game)
{
	if (argc != 2 || ft_strrncmp(argv[1], ".cub", 4) != 0 || ft_strlen(argv[1]) < 5)
	{
		ft_putendl_fd(INVALID_MAP_EXTENSTION, 2);
		exit(1);
	}
	game->map = read_to_map(argv[1]);
	ft_print_two_d_arr(game->map);
	save_info(game);
	printf("\n");
	ft_print_two_d_arr(game->map);
	// validate saved info.
	// validate map content.
	ft_free_arr(game->map);
	free_texture(game->texture);
}
