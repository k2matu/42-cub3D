/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:07:15 by hzibari           #+#    #+#             */
/*   Updated: 2024/11/03 09:52:22 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rotate_left(t_struct *game)
{
	game->ray->player_angle -= ROTATE_SPEED;
	if (game->ray->player_angle < 0)
		game->ray->player_angle += 2 * M_PI;
}

static void	rotate_right(t_struct *game)
{
	game->ray->player_angle += ROTATE_SPEED;
	if (game->ray->player_angle >= 2 * M_PI)
		game->ray->player_angle -= 2 * M_PI;
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_struct	*game;

	game = (t_struct *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_putendl_fd(GAME_CLOSED, 1);
		mlx_close_window(game->mlx);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game);
}
