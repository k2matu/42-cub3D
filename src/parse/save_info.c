/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:39:45 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/03 10:23:30 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**save_map_rm_elems(t_struct *game, char **content2d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		content2d = arr_pop(content2d, 0);
		if (!content2d)
			clean_exit(game, ERR_MALLOC, content2d);
		i++;
	}
	return (content2d);
}

static void	save_elem(char **dst, char *src, t_struct *game, char **content2d)
{
	while (*src == ' ')
		src++;
	if (*dst == NULL)
		*dst = ft_strdup(src);
	if (!*dst)
		clean_exit(game, ERR_MALLOC, content2d);
}

static void	save_elems(t_struct *game, char **content2d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(content2d[i], "NO ", 3))
			save_elem(&game->elem.north, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "SO ", 3))
			save_elem(&game->elem.south, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "WE ", 3))
			save_elem(&game->elem.west, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "EA ", 3))
			save_elem(&game->elem.east, content2d[i] + 3, game, content2d);
		else if (!ft_strncmp(content2d[i], "F ", 2))
			save_elem(&game->elem.floor, content2d[i] + 2, game, content2d);
		else if (!ft_strncmp(content2d[i], "C ", 2))
			save_elem(&game->elem.ceiling, content2d[i] + 2, game, content2d);
		i++;
	}
}

void	save_info(t_struct *game, char **content2d)
{
	save_elems(game, content2d);
	game->map = save_map_rm_elems(game, content2d);
}
