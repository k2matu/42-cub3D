/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halgordzibari <halgordzibari@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:04:54 by halgordziba       #+#    #+#             */
/*   Updated: 2024/10/18 19:09:45 by halgordziba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double check_y_hits(t_struct *game)
{
	double  distance;
	double  y_inter;
	double  x_inter;
	double	x_step;
	double	y_step;
	
	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(game->ray->ray_angle);
	fix_inters_for_y(game, &y_inter, &x_inter, &x_step, &y_step);
	while(1) // maybe need a limit untill map high or wight incase ray is staright then it will never find wall; 
	{
		if (check_wall_hit(game, x_inter, y_inter))
			break;
		y_inter += y_step;
		x_inter += x_step;
		distance = sqrt(pow(x_inter - game->ray->pixel_pos_x, 2) + pow(y_inter - game->ray->pixel_pos_y, 2));
	}
	return (distance);
}

double check_x_hits(t_struct *game)
{
	double  distance;
	double  y_inter;
	double  x_inter;
	double	x_step;
	double	y_step;
	
	y_step = TILE_SIZE * tan(game->ray->ray_angle);;
	x_step = TILE_SIZE ;
	fix_inters_for_x(game, &y_inter, &x_inter, &x_step, &y_step);
	while(1) // maybe same as the top one
	{
		if (check_wall_hit(game, x_inter, y_inter))
			break;
		y_inter += y_step;
		x_inter += x_step;
		distance = sqrt(pow(x_inter - game->ray->pixel_pos_x, 2) + pow(y_inter - game->ray->pixel_pos_y, 2));
	}
	return (distance);
}

double cast_single_ray(t_struct *game)
{
	double  y_distance;
	double  x_distance;
	
	y_distance = check_y_hits(game);
	x_distance = check_x_hits(game);
	if (y_distance < x_distance)
		return (y_distance);
	return (x_distance);
}

void raycasting(t_struct *game)
{
	double distance;
	int ray_id;

	ray_id = 0;
	distance = 0;

	game->ray->ray_angle = game->ray->player_angle - (game->ray->fov_radians / 2);
	while (ray_id < S_W)
	{
		// if (game->ray.ray_angle > 2 * M_PI)
		// 	game->ray.ray_angle -= 2 * M_PI;
		// if (game->ray.ray_angle < 0)
		// 	game->ray.ray_angle += 2 * M_PI;
		nor_angle(game->ray->ray_angle);
		distance = cast_single_ray(game);
		//render_wall();
		game->ray->ray_angle += game->ray->fov_radians / S_W;
		ray_id++;
	}
}
