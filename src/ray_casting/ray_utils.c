/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:18:41 by halgordziba       #+#    #+#             */
/*   Updated: 2024/10/28 13:53:01 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fix_inters_for_y(t_struct *game, float *y_inter, float *x_inter)
{
	*y_inter = floor(game->ray->pixel_pos_y / TILE_SIZE) * TILE_SIZE;
	if (game->ray->ray_angle > 0 && game->ray->ray_angle < M_PI)
		*y_inter += TILE_SIZE;
	if (game->ray->ray_angle > M_PI)
		game->ray->y_step *= -1;
	*x_inter = game->ray->pixel_pos_x + (*y_inter - game->ray->pixel_pos_y)
		/ tan(game->ray->ray_angle);
	if (game->ray->ray_angle > M_PI / 2
		&& game->ray->ray_angle < (3 * M_PI) / 2)
		if (game->ray->x_step > 0)
			game->ray->x_step *= -1;
	if (!(game->ray->ray_angle > M_PI / 2
			&& game->ray->ray_angle < (3 * M_PI) / 2))
		if (game->ray->x_step < 0)
			game->ray->x_step *= -1;
}

void	fix_inters_for_x(t_struct *game, float *y_inter, float *x_inter)
{
	*x_inter = floor(game->ray->pixel_pos_x / TILE_SIZE) * TILE_SIZE;
	if (game->ray->ray_angle < M_PI / 2
		|| game->ray->ray_angle > (3 * M_PI) / 2)
		*x_inter += TILE_SIZE;
	if (game->ray->ray_angle > M_PI / 2
		&& game->ray->ray_angle < (3 * M_PI) / 2)
		game->ray->x_step *= -1;
	*y_inter = game->ray->pixel_pos_y + (*x_inter - game->ray->pixel_pos_x)
		* tan(game->ray->ray_angle);
	if ((game->ray->ray_angle > 0 && game->ray->ray_angle < (M_PI)))
		if (game->ray->y_step < 0)
			game->ray->y_step *= -1;
	if (game->ray->ray_angle > (M_PI))
		if (game->ray->y_step > 0)
			game->ray->y_step *= -1;
}

int	check_wall_hit(t_struct *game, float x_inter, float y_inter)
{
	int	y_wall;
	int	x_wall;

	if (x_inter < 0 || y_inter < 0)
		return (1);
	if (!(game->ray->ray_angle > 0 && game->ray->ray_angle < M_PI))
		y_inter -= 1;
	else
		y_inter += 1;
	if (!(game->ray->ray_angle < M_PI / 2
			|| game->ray->ray_angle > (3 * M_PI) / 2))
		x_inter -= 1;
	else
		x_inter += 1;
	y_wall = floor (y_inter / TILE_SIZE);
	x_wall = floor (x_inter / TILE_SIZE);
	if (y_wall < 0 || y_wall >= game->row || x_wall < 0 || x_wall >= game->col)
		return (1);
	if (game->map[y_wall][x_wall] == '1')
		return (1);
	return (0);
}
