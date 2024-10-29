/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/10/29 10:08:53 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player(t_struct *game)
{
	game->ray = ft_calloc(1, sizeof(t_ray));
	if (!game->ray)
	{
		safe_mlx_terminate(game);
		ft_putendl_fd(ERR_CALLOC, 2);
		exit(EXIT_FAILURE);
	}
	game->ray->pixel_pos_x = game->player.pos_x * TILE_SIZE + TILE_SIZE / 2;
	game->ray->pixel_pos_y = game->player.pos_y * TILE_SIZE + TILE_SIZE / 2;
	game->ray->fov_radians = (FOV * M_PI) / 180;
	if (game->player.direction == 'E')
		game->ray->player_angle = 0;
	else if (game->player.direction == 'N')
		game->ray->player_angle = M_PI / 2;
	else if (game->player.direction == 'W')
		game->ray->player_angle = M_PI;
	else
		game->ray->player_angle = (3 * M_PI) / 2;
	game->ray->ray_angle = 0;
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	game_loop(t_struct *game)
{
	game->img = mlx_new_image(game->mlx, S_W, S_H);
	raycasting(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

int	main(int argc, char **argv)
{
	static t_struct	game;

	parse(argc, argv, &game);
	game.mlx = safe_mlx_init(&game);
	init_player(&game);
	game_loop(&game);
	mlx_key_hook(game.mlx, &key_press, &game);
	mlx_loop(game.mlx);
	safe_mlx_terminate(&game);
	return (0);
}
