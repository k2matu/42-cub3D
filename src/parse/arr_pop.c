/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:03:47 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/06 13:53:36 by kmatjuhi         ###   ########.fr       */
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

static void	free_arr(char **arr, int size)
{
	while (size > 0)
		free(arr[--size]);
	free(arr);
}

static char	**remove_row(char **old_arr, char **new_arr, int row)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (old_arr[i])
	{
		if (i != row)
		{
			new_arr[j] = ft_strdup(old_arr[i]);
			if (!new_arr[j])
			{
				free_arr(new_arr, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	new_arr[j] = NULL;
	return (new_arr);
}

char	**arr_pop(char **old_arr, int row)
{
	char	**new_arr;
	int		rows;

	if (!old_arr)
		return (NULL);
	rows = count_rows(old_arr);
	if (row < 0 || row >= rows)
		return (old_arr);
	new_arr = malloc(rows * sizeof(char *));
	if (!new_arr)
	{
		ft_putendl_fd(MALLOC_ERR, 2);
		return (NULL);
	}
	new_arr = remove_row(old_arr, new_arr, row);
	if (!new_arr)
		return (NULL);
	ft_free_arr(old_arr);
	return (new_arr);
}
