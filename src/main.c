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
	// if (game->player.direction == 'E')
	// 	game->ray->player_angle = 0;
	// else if (game->player.direction == 'N')
	// 	game->ray->player_angle = M_PI / 2;
	// else if (game->player.direction == 'W')
	// 	game->ray->player_angle = M_PI;
	// else
	// 	game->ray->player_angle = (3 * M_PI) / 2;
	game->ray->player_angle = M_PI / 2;
	game->ray->map_hight = count_map_hight(game);
	game->ray->map_weight = ft_strlen(game->map[0]);
	game->ray->distance = 0;
	game->ray->ray_angle = 0;
	game->ray->distance = 0;
}

float	nor_angle(float angle)	// normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}








void mlx_draw_rectangle(mlx_image_t* img, int x, int y, int width, int height, uint32_t color) 
{
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            // Ensure the pixel coordinates are within the window bounds
            if (i >= 0 && i < S_W && j >= 0 && j < S_H) {
                mlx_put_pixel(img, i, j, color);
            }
        }
    }
}

void mlx_draw_line(mlx_image_t* img, int x0, int y0, int x1, int y1, uint32_t color) 
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    // // Bounds checking to prevent segfaults
    // if (x0 < 0 || x0 >= img->width || y0 < 0 || y0 >= img->height || 
    //     x1 < 0 || x1 >= img->width || y1 < 0 || y1 >= img->height)
    // {
    //     printf("Coordinates out of bounds: (%d, %d) to (%d, %d)\n", x0, y0, x1, y1);
    //     return;
    // }

    while (1) {
        mlx_put_pixel(img, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_map(t_struct *game)
{
    int x;
    int y;
    int color;

    for (y = 0; y < game->row; y++)
    {
        for (x = 0; x < game->col; x++)
        {
            if (game->map[y][x] == '1')
            {
                color = 0xba01FF; // Blue for walls
            }
            else
            {
                color = 0x0000FF; // Black for empty spaces
            }
            
            mlx_draw_rectangle(game->img, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
        }
    }
}

void draw_player(t_struct *game)
{
    int player_size = 5;
    int player_x = game->ray->pixel_pos_x;
    int player_y = game->ray->pixel_pos_y;

    mlx_draw_rectangle(game->img, player_x - player_size / 2, player_y - player_size / 2, player_size, player_size, 0xFF00FFFF); // Red for player
}









void	game_loop(t_struct *game)
{
	game->img = mlx_new_image(game->mlx, S_W, S_H);	

	// printf("x pos: %d\n", game->player.pos_x);
	// printf("y pos: %d\n", game->player.pos_y);
	// printf("x pixel: %f\n", game->ray->pixel_pos_x);
	// printf("y pixel: %f\n", game->ray->pixel_pos_y);


	draw_map(game);
	draw_player(game);

	raycasting(game); // BORROWED UNTIL PARTNER FIXES THIS PART.

	mlx_image_to_window(game->mlx, game->img, 0, 0);
	//game->ray = ft_calloc(1, sizeof(t_ray));
}

int	main(int argc, char **argv)
{
	static t_struct	game;

	parse(argc, argv, &game);
	game.mlx = safe_mlx_init(&game);
	init_player(&game);
	game_loop(&game);
	mlx_loop(game.mlx);
	safe_mlx_terminate(&game);
	return (0);
}
