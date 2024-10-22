/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:18:41 by halgordziba       #+#    #+#             */
/*   Updated: 2024/10/22 18:49:48 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fix_inters_for_y(t_struct *game, double *y_inter, double *x_inter, double *x_step, double *y_step)
{
	*y_inter = floor(game->ray->pixel_pos_y / TILE_SIZE) * TILE_SIZE;
	if (game->ray->ray_angle > 0 && game->ray->ray_angle < M_PI)
		*y_inter += TILE_SIZE;
	else
		*y_step *= -1;
	*x_inter = game->ray->pixel_pos_x + (*y_inter - game->ray->pixel_pos_y) / tan(game->ray->ray_angle);
	if (((game->ray->ray_angle > M_PI/2 && game->ray->ray_angle < (3 * M_PI/2)) && *x_step > 0))
		*x_step *= -1;
}

void	fix_inters_for_x(t_struct *game, double *y_inter, double *x_inter, double *x_step, double *y_step)
{
	*x_inter = floor(game->ray->pixel_pos_x / TILE_SIZE) * TILE_SIZE;
	if ((game->ray->ray_angle < M_PI/2 || game->ray->ray_angle > (3 * M_PI/2)))
		*x_inter += TILE_SIZE;
	else
		*x_step *= -1;
	*y_inter = game->ray->pixel_pos_y + (*x_inter - game->ray->pixel_pos_x) * tan(game->ray->ray_angle);
	if (((game->ray->ray_angle > 0 && game->ray->ray_angle < (M_PI)) && *y_step < 0))
		*y_step *= -1;
}

int	check_wall_hit(t_struct *game, double x_inter, double y_inter)
{
	int y_wall;
	int x_wall;

	if (x_inter < 0 || y_inter < 0)
		return (1);
	y_wall = floor (y_inter / TILE_SIZE);
	x_wall = floor (x_inter / TILE_SIZE);
	if (y_wall < 0 || y_wall >= game->ray->map_hight || x_wall < 0 || x_wall >= game->ray->map_weight)
		return (1);
	if (game->map[y_wall][x_wall] == '1')
		return(1);
	return(0);
}

