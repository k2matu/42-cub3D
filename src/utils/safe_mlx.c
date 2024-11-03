/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:13:46 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/03 09:48:44 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	safe_mlx_init(t_struct *game)
{
	game->mlx = mlx_init(S_W, S_H, "Cub3D", 1);
	if (!game->mlx)
	{
		free(game->content);
		ft_free_arr(game->map);
		free_elements(&(game->elem));
		ft_putendl_fd(ERR_MLX, 2);
		exit(EXIT_FAILURE);
	}
}

void	safe_mlx_terminate(t_struct *game)
{
	mlx_terminate(game->mlx);
	free(game->content);
	ft_free_arr(game->map);
	free_elements(&(game->elem));
	if (game->texture)
	{
		if (game->texture->south)
			mlx_delete_texture(game->texture->south);
		if (game->texture->north)
			mlx_delete_texture(game->texture->north);
		if (game->texture->east)
			mlx_delete_texture(game->texture->east);
		if (game->texture->west)
			mlx_delete_texture(game->texture->west);
		free(game->texture);
	}
	if (game->ray)
		free(game->ray);
}
