/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:07:15 by hzibari           #+#    #+#             */
/*   Updated: 2024/10/31 14:19:07 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_up(t_struct *game)
{
	float new_x = game->ray->pixel_pos_x + cos(game->ray->player_angle) * MOVE_SPEED;
	float new_y = game->ray->pixel_pos_y + sin(game->ray->player_angle) * MOVE_SPEED;

	if (game->map[(int)(new_x / TILE_SIZE)][(int)(new_y / TILE_SIZE)] == '0')
	{
		game->ray->pixel_pos_x = new_x;
		game->ray->pixel_pos_y = new_y;
	}
}

static void	move_down(t_struct *game)
{
	float new_x = game->ray->pixel_pos_x - cos(game->ray->player_angle) * MOVE_SPEED;
	float new_y = game->ray->pixel_pos_y - sin(game->ray->player_angle) * MOVE_SPEED;

	if (game->map[(int)(new_x / TILE_SIZE)][(int)(new_y / TILE_SIZE)] == '0')
	{
		game->ray->pixel_pos_x = new_x;
		game->ray->pixel_pos_y = new_y;
	}
}

static void	move_left(t_struct *game)
{
	float new_x = game->ray->pixel_pos_x + cos(game->ray->player_angle - M_PI / 2) * MOVE_SPEED;
	float new_y = game->ray->pixel_pos_y + sin(game->ray->player_angle - M_PI / 2) * MOVE_SPEED;

	if (game->map[(int)(new_x / TILE_SIZE)][(int)(new_y / TILE_SIZE)] == '0')
	{
		game->ray->pixel_pos_x = new_x;
		game->ray->pixel_pos_y = new_y;
	}
}

static void	move_right(t_struct *game)
{
	float new_x = game->ray->pixel_pos_x + cos(game->ray->player_angle + M_PI / 2) * MOVE_SPEED;
	float new_y = game->ray->pixel_pos_y + sin(game->ray->player_angle + M_PI / 2) * MOVE_SPEED;

	if (game->map[(int)(new_x / TILE_SIZE)][(int)(new_y / TILE_SIZE)] == '0')
	{
		game->ray->pixel_pos_x = new_x;
		game->ray->pixel_pos_y = new_y;
	}
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_struct	*game;

	game = (t_struct *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		printf("Game closed ESC was pressed\n");
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
}
