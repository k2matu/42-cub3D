/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:43:55 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/05 13:59:23 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_collision(t_struct *game, float new_x, float new_y)
{
	if (game->map[(int)((new_y + BUFFER_DISTANCE)
			/ TILE_SIZE)][(int)((new_x + BUFFER_DISTANCE) / TILE_SIZE)] == '1')
		return (0);
	if (game->map[(int)((new_y + BUFFER_DISTANCE)
			/ TILE_SIZE)][(int)((new_x - BUFFER_DISTANCE) / TILE_SIZE)] == '1')
		return (0);
	if (game->map[(int)((new_y - BUFFER_DISTANCE)
			/ TILE_SIZE)][(int)((new_x + BUFFER_DISTANCE) / TILE_SIZE)] == '1')
		return (0);
	if (game->map[(int)((new_y - BUFFER_DISTANCE)
			/ TILE_SIZE)][(int)((new_x - BUFFER_DISTANCE) / TILE_SIZE)] == '1')
		return (0);
	return (1);
}

void	move_up(t_struct *game)
{
	float	new_x;
	float	new_y;

	new_x = game->ray->pixel_pos_x + cos(game->ray->player_angle) * MOVE_SPEED;
	new_y = game->ray->pixel_pos_y + sin(game->ray->player_angle) * MOVE_SPEED;
	if (check_collision(game, new_x, new_y))
	{
		game->ray->pixel_pos_x = new_x;
		game->ray->pixel_pos_y = new_y;
	}
}

void	move_down(t_struct *game)
{
	float	new_x;
	float	new_y;

	new_x = game->ray->pixel_pos_x - cos(game->ray->player_angle) * MOVE_SPEED;
	new_y = game->ray->pixel_pos_y - sin(game->ray->player_angle) * MOVE_SPEED;
	if (check_collision(game, new_x, new_y))
	{
		game->ray->pixel_pos_x = new_x;
		game->ray->pixel_pos_y = new_y;
	}
}

void	move_left(t_struct *game)
{
	float	new_x;
	float	new_y;

	new_x = game->ray->pixel_pos_x + cos(game->ray->player_angle - M_PI / 2)
		* MOVE_SPEED;
	new_y = game->ray->pixel_pos_y + sin(game->ray->player_angle - M_PI / 2)
		* MOVE_SPEED;
	if (check_collision(game, new_x, new_y))
	{
		game->ray->pixel_pos_x = new_x;
		game->ray->pixel_pos_y = new_y;
	}
}

void	move_right(t_struct *game)
{
	float	new_x;
	float	new_y;

	new_x = game->ray->pixel_pos_x + cos(game->ray->player_angle + M_PI / 2)
		* MOVE_SPEED;
	new_y = game->ray->pixel_pos_y + sin(game->ray->player_angle + M_PI / 2)
		* MOVE_SPEED;
	if (check_collision(game, new_x, new_y))
	{
		game->ray->pixel_pos_x = new_x;
		game->ray->pixel_pos_y = new_y;
	}
}
