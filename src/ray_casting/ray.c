/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:04:54 by halgordziba       #+#    #+#             */
/*   Updated: 2024/11/04 15:57:17 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	check_y_hits(t_struct *game)
{
	float	y_inter;
	float	x_inter;

	game->ray->y_step = TILE_SIZE;
	game->ray->x_step = TILE_SIZE / tan(game->ray->ray_angle);
	fix_inters_for_y(game, &y_inter, &x_inter);
	while (1)
	{
		if (check_wall_hit(game, x_inter, y_inter))
			break ;
		y_inter += game->ray->y_step;
		x_inter += game->ray->x_step;
	}
	game->ray->x_hit = x_inter;
	// game->ray->yy_hit = y_inter;
	return (sqrt(pow(x_inter - game->ray->pixel_pos_x, 2)
			+ pow(y_inter - game->ray->pixel_pos_y, 2)));
}

float	check_x_hits(t_struct *game)
{
	float	y_inter;
	float	x_inter;

	game->ray->y_step = TILE_SIZE * tan(game->ray->ray_angle);
	game->ray->x_step = TILE_SIZE;
	fix_inters_for_x(game, &y_inter, &x_inter);
	while (1)
	{
		if (check_wall_hit(game, x_inter, y_inter))
			break ;
		y_inter += game->ray->y_step;
		x_inter += game->ray->x_step;
	}
	game->ray->y_hit = y_inter;
	return (sqrt(pow(x_inter - game->ray->pixel_pos_x, 2)
			+ pow(y_inter - game->ray->pixel_pos_y, 2)));
}

float	cast_single_ray(t_struct *game)
{
	float	y_distance;
	float	x_distance;

	y_distance = check_y_hits(game);
	x_distance = check_x_hits(game);
	if (y_distance <= x_distance)
	{
		game->ray->flag = 1;
		return (y_distance);
	}
	return (x_distance);
}

void	raycasting(t_struct *game)
{
	float	distance;
	int		ray_id;

	ray_id = 0;
	distance = 0;
	game->ray->ray_angle = game->ray->player_angle
		- (game->ray->fov_radians / 2);
	while (ray_id < S_W)
	{
		game->ray->flag = 0;
		game->ray->ray_angle = nor_angle(game->ray->ray_angle);
		distance = cast_single_ray(game);
		render_wall(game, ray_id, distance);
		game->ray->ray_angle += (game->ray->fov_radians / S_W);
		ray_id++;
	}
}
