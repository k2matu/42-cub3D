/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:16:03 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/06 12:57:36 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_elements(t_element element)
{
	if (element.north)
		free(element.north);
	if (element.south)
		free(element.south);
	if (element.west)
		free(element.west);
	if (element.east)
		free(element.east);
	if (element.floor)
		free(element.floor);
	if (element.ceiling)
		free(element.ceiling);
}
