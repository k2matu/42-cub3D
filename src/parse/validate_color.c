/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:43:42 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/14 21:20:22 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		if (!arr[i])
		{
			ft_free_arr(arr);
			clean_exit(game, ERR_RGB_VAL, game->map);
		}
		rgb = ft_atoi(arr[i]);
		if (arr[i][0] == '\0' || rgb > 255 || rgb < 0 || !is_num(arr[i]))
			is_valid = false;
		i++;
	}
	if (!is_valid)
	{
		ft_free_arr(arr);
		clean_exit(game, ERR_RGB_VAL, game->map);
	}
}

static int	convert_color_rgba(char **arr)
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

static void	validate_comma(t_struct *game, char *elem)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (elem[i] == ' ')
		i++;
	if (elem[i] == ',')
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	while (elem[i])
	{
		if (elem[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	i--;
	while (elem[i] == ' ')
		i--;
	if (elem[i] == ',')
		clean_exit(game, ERR_ELEM_INVALID, game->map);
}

int	validate_color(t_struct *game, char *elem)
{
	char	**rgb_char;
	int		i;
	int		color;

	i = 0;
	validate_comma(game, elem);
	rgb_char = ft_split(elem, ',');
	if (!rgb_char)
		clean_exit(game, ERR_MALLOC, game->map);
	while (rgb_char[i])
		i++;
	if (i != 3)
	{
		ft_free_arr(rgb_char);
		clean_exit(game, ERR_ELEM_INVALID, game->map);
	}
	check_color_range(game, rgb_char);
	color = convert_color_rgba(rgb_char);
	ft_free_arr(rgb_char);
	return (color);
}
