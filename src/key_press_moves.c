/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:07:15 by hzibari           #+#    #+#             */
/*   Updated: 2024/10/31 11:32:41 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_up(t_struct *game)
{
	if (game->map[(int)game->ray->pixel_pos_y - 1]
		[(int)game->ray->pixel_pos_x] == '1')
		return ;
	game->ray->pixel_pos_y--;
}

static void	move_down(t_struct *game)
{
	if (game->map[(int)game->ray->pixel_pos_y + 1]
		[(int)game->ray->pixel_pos_x] == '1')
		return ;
	game->ray->pixel_pos_y++;
}

static void	move_left(t_struct *game)
{
	if (game->map[(int)game->ray->pixel_pos_y]
		[(int)game->ray->pixel_pos_x - 1] == '1')
		return ;
	game->ray->pixel_pos_x--;
}

static void	move_right(t_struct *game)
{
	if (game->map[(int)game->ray->pixel_pos_y]
		[(int)game->ray->pixel_pos_x + 1] == '1')
		return ;
	game->ray->pixel_pos_x++;
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_struct	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_up(game);
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_down(game);
	if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left(game);
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(game);
}
