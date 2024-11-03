/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:57:56 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/01 11:13:55 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_strdup_fill(const char *s1, int col)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((col + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < col)
	{
		ptr[i] = '.';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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

char	**ft_arrdup(char **arr, int col)
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
		map[i] = ft_strdup_fill(arr[i], col);
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
