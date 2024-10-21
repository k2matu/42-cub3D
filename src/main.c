/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student->hive->fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:31:32 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/27 14:49:39 by kmatjuhi         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int count_map_hight(t_struct *game)
{
	int i;

	i = 0;
	while(game->map[i])
		i++;
	return(i);
}

void init_ray_info(t_struct *game)
{
	game->ray->pixel_pos_x = game->player.pos_x * TILE_SIZE + TILE_SIZE / 2;
	game->ray->pixel_pos_y = game->player.pos_y * TILE_SIZE + TILE_SIZE / 2;
	game->ray->player_angle = M_PI;
	game->ray->fov_radians = (FOV * M_PI) / 180;
	game->ray->map_hight = count_map_hight(game);
	game->ray->map_weight = ft_strlen(game->map[0]);
	game->ray->distance = 0;
	game->ray->ray_angle = 0;
	game->ray->distance = 0;
}

void	init_player(t_struct *game)
{
	game->plyr_px = ft_calloc(1, sizeof(t_player_px));
	if (!game->plyr_px)
	{
		safe_mlx_terminate(game);
		ft_putendl_fd(ERR_CALLOC, 2);
		exit(EXIT_FAILURE);
	}
	game->plyr_px->pos_px_x = game->player.pos_x * TILE_SIZE + TILE_SIZE / 2;
	game->plyr_px->pos_px_y = game->player.pos_y * TILE_SIZE + TILE_SIZE / 2;
	game->plyr_px->fov_radians = FOV * (M_PI / 180);
	if (game->player.direction == 'E')
		game->plyr_px->angle = 0;
	else if (game->player.direction == 'N')
		game->plyr_px->angle = M_PI / 2;
	else if (game->player.direction == 'W')
		game->plyr_px->angle = M_PI;
	else
		game->plyr_px->angle = (3 * M_PI) / 2;
}

float	nor_angle(float angle)	// normalize the angle
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
	game->ray = ft_calloc(1, sizeof(t_ray));
	raycasting(game); // BORROWED UNTIL PARTNER FIXES THIS PART.
}

int	main(int argc, char **argv)
{
	static t_struct	game;

	parse(argc, argv, &game);
	game.mlx = safe_mlx_init(&game);
	init_player(&game);
	init_ray_info(&game);
	game_loop(&game);
	mlx_loop(game.mlx);
	safe_mlx_terminate(&game);
	return (0);
}
