/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 08:10:06 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/05 13:25:08 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_png_files(t_struct *game)
{
	if (ft_strrncmp(game->elem.north, ".png", 4))
		clean_exit(game, ERR_FILE_NOT_PNG, game->map);
	if (ft_strrncmp(game->elem.south, ".png", 4))
		clean_exit(game, ERR_FILE_NOT_PNG, game->map);
	if (ft_strrncmp(game->elem.east, ".png", 4))
		clean_exit(game, ERR_FILE_NOT_PNG, game->map);
	if (ft_strrncmp(game->elem.west, ".png", 4))
		clean_exit(game, ERR_FILE_NOT_PNG, game->map);
}

static void	check_file_exist(t_struct *game)
{
	safe_open_file(game, game->elem.north);
	safe_open_file(game, game->elem.south);
	safe_open_file(game, game->elem.east);
	safe_open_file(game, game->elem.west);
}

void	validate_elems(t_struct *game)
{
	if (!game->elem.north || !game->elem.south || !game->elem.west || \
	!game->elem.east || !game->elem.floor || !game->elem.ceiling)
		clean_exit(game, ERR_ELEM_MISSING, game->map);
	check_png_files(game);
	check_file_exist(game);
	game->elem.f_rgba = validate_color(game, game->elem.floor);
	game->elem.c_rgba = validate_color(game, game->elem.ceiling);
}
