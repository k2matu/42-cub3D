/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 08:10:06 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/10/29 12:04:42 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_png_files(t_struct *game)
{
	if (ft_strrncmp(game->elem.north, ".png", 4))
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	if (ft_strrncmp(game->elem.south, ".png", 4))
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	if (ft_strrncmp(game->elem.east, ".png", 4))
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	if (ft_strrncmp(game->elem.west, ".png", 4))
		clean_exit(game, ERR_ELEM_INVALID, game->map);
}

static bool	is_num(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static void	check_color_range(t_struct *game, char **arr)
{
	int		rgb;
	int		i;
	bool	is_valid;

	i = 0;
	is_valid = true;
	while (arr[i])
	{
		arr[i] = ft_strtrim(arr[i], " ");
		rgb = ft_atoi(arr[i]);
		if (rgb > 255 || rgb < 0)
			is_valid = false;
		if (!is_num(arr[i]))
			is_valid = false;
		i++;
	}
	if (!is_valid)
	{
		ft_free_arr(arr);
		clean_exit(game, ERR_RGB_VAL, game->map);
	}
}

static int	convert_color_rgba(t_struct *game, char **arr)
{
	int		i;
	int		color;
	int		range[3];

	i = 0;
	while (arr[i])
	{
		range[i] = ft_atoi(arr[i]);
		i++;
	}
	color = (range[0] << 24) | (range[1] << 16) | (range[2] << 8) | 255;
	return (color);
}

static int	check_color(t_struct *game, char *elem)
{
	char	**rgb_char;
	int		i;
	int		color;

	i = 0;
	rgb_char = ft_split(elem, ',');
	while (rgb_char[i])
		i++;
	if (i != 3)
	{
		ft_free_arr(rgb_char);
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	}
	check_color_range(game, rgb_char);
	color = convert_color_rgba(game, rgb_char);
	ft_free_arr(rgb_char);
	return (color);
}

void	validate_elems(t_struct *game)
{
	if (!game->elem.north || !game->elem.south || !game->elem.west || \
	!game->elem.east || !game->elem.floor || !game->elem.ceiling)
		clean_exit(game, ERR_ELEM_MISSING, game->map);
	check_png_files(game);
	game->elem.f_rgba = check_color(game, game->elem.floor);
	game->elem.c_rgba = check_color(game, game->elem.ceiling);
}
