/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:13:46 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/10/21 15:08:54 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

mlx_t	*safe_mlx_init(t_struct *game) {
	mlx_t	*mlx;

	mlx = mlx_init(S_W, S_H, "Cub3D", 1);
	if (!mlx)
	{
		free(game->content);
		ft_free_arr(game->map);
		free_elements(&(game->elem));
		ft_putendl_fd(ERR_MLX, 2);
		exit(EXIT_FAILURE);
	}
	return (mlx);
}

void	safe_mlx_terminate(t_struct *game) {
	mlx_terminate(game->mlx);
	free(game->content);
	ft_free_arr(game->map);
	free_elements(&(game->elem));
	if (game->ray)
		free(game->ray);
}
