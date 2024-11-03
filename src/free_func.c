/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:16:03 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/03 09:19:49 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_elements(t_element *elem)
{
	if (elem->north)
		free(elem->north);
	if (elem->south)
		free(elem->south);
	if (elem->west)
		free(elem->west);
	if (elem->east)
		free(elem->east);
	if (elem->floor)
		free(elem->floor);
	if (elem->ceiling)
		free(elem->ceiling);
}

void	clean_exit(t_struct *game, char *msg, char **arr)
{
	free(game->content);
	ft_free_arr(arr);
	free_elements(&(game->elem));
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
