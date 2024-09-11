/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:57:56 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/11 13:11:07 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_rows(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static void	free_arr(char **dest, int i)
{
	while (i > 0)
	{
		i--;
		free(dest[i]);
	}
	free(dest);
}

char	**ft_arrdup(char **arr)
{
	char	**map;
	int		row;
	int		i;

	i = 0;
	row = count_rows(arr);
	map = malloc(sizeof(char *) * (row + 1));
	if (!map)
		return (NULL);
	while (i < row)
	{
		map[i] = ft_strdup(arr[i]);
		if (!map[i])
		{
			free_arr(map, i);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}
