/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 08:10:06 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/09 08:36:17 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_xpm_files(t_struct *game)
{
	if (ft_strrncmp(game->elem.north, ".xpm", 4))
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	if (ft_strrncmp(game->elem.south, ".xpm", 4))
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	if (ft_strrncmp(game->elem.east, ".xpm", 4))
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	if (ft_strrncmp(game->elem.west, ".xpm", 4))
		clean_exit(game, ERR_ELEM_INVALID, game->map);
}

static void	check_color_range(t_struct *game, char **arr)
{
	int	rgb;
	int	i;

	i = 0;
	while (arr[i])
	{
		rgb = ft_atoi(arr[i]);
		if (rgb > 255 || rgb < 0)
		{
			ft_free_arr(arr);
			clean_exit(game, ERR_RGB_VAL, game->map);
		}
		if (rgb == 0 && ft_strlen(arr[i]) != 1 && arr[i][0] != '0')
		{
			ft_free_arr(arr);
			clean_exit(game, "ERROR ON 0", game->map);
		}
		i++;
	}
}

static void	check_color(t_struct *game)
{
	char	**rgb_char;
	int		i;

	i = 0;
	rgb_char = ft_split(game->elem.floor, ',');
	while (rgb_char[i])
		i++;
	if (i != 3)
	{
		ft_free_arr(rgb_char);
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	}
	check_color_range(game, rgb_char);
}

void	validate_elems(t_struct *game)
{
	if (!game->elem.north || !game->elem.south || !game->elem.west || \
	!game->elem.east || !game->elem.floor || !game->elem.ceiling)
		clean_exit(game, ERR_ELEM_MISSING, game->map);
	check_xpm_files(game);
	check_color(game);
}
