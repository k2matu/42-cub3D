/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:46:47 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/10/31 13:31:13 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

mlx_texture_t	*get_texture(t_struct *game)
{
	if (game->ray->flag == 0)
	{
		if (game->ray->ray_angle > M_PI / 2 && 
			game->ray->ray_angle < 3 * (M_PI / 2))
			return (game->texture->west);
		else
			return (game->texture->east);
	}
	else
	{
		if (game->ray->ray_angle > 0 && game->ray->ray_angle < M_PI)
			return (game->texture->south);
		else
			return (game->texture->north);
	}
}

void	draw_wall(t_struct *game, int ray, int top_pxl, int bottom_pxl)
{
	mlx_texture_t	*texture;
	double			texture_step;
	double			y_texture;
	int				x_texture;
	int				color;

	y_texture = 0;
	texture = get_texture(game);
	texture_step = (double)texture->height / (bottom_pxl - top_pxl);
	x_texture = ray % texture->width;
	while (top_pxl < bottom_pxl)
	{
		color = *((uint32_t *)texture->pixels + 
				((int)y_texture * texture->width) + x_texture);
		if (!(ray < 0 || ray >= S_W || top_pxl < 0 || top_pxl >= S_H))
			mlx_put_pixel(game->img, ray, top_pxl, color);
		top_pxl++;
		y_texture += texture_step;
	}
}

void	draw_floor_ceiling(t_struct *game, int ray, int top_pxl, int bottom_pxl)
{
	while (bottom_pxl < S_H)
	{
		if (!(ray < 0 || ray >= S_W || top_pxl < 0 || top_pxl >= S_H))
			mlx_put_pixel(game->img, ray, bottom_pxl, game->elem.f_rgba);
		bottom_pxl++;
	}
	bottom_pxl = 0;
	while (bottom_pxl < top_pxl)
	{
		if (!(ray < 0 || ray >= S_W || top_pxl < 0 || top_pxl >= S_H))
			mlx_put_pixel(game->img, ray, bottom_pxl, game->elem.c_rgba);
		bottom_pxl++;
	}
}

void	render_wall(t_struct *game, int ray, float distance)
{
	double	dist_player;
	double	wall_h;
	double	bottom_pxl;
	double	top_pxl;

	distance *= cos(game->ray->ray_angle - game->ray->player_angle);
	dist_player = (S_W / 2) / tan((game->ray->fov_radians) / 2);
	wall_h = TILE_SIZE / distance * dist_player;
	bottom_pxl = (S_H / 2) + (wall_h / 2);
	top_pxl = (S_H / 2) - (wall_h / 2);
	if (bottom_pxl > S_H)
		bottom_pxl = S_H;
	if (top_pxl < 0)
		top_pxl = 0;
	draw_wall(game, ray, top_pxl, bottom_pxl);
	draw_floor_ceiling(game, ray, top_pxl, bottom_pxl);
}
