#include "cub3D.h"

void	my_game_pixel_put(t_struct *game, int x, int y, int color)	// put the pixel
{
	if (x < 0) // check the x position
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0) // check the y position
		return ;
	else if (y >= S_H)
		return ;
	mlx_put_pixel(game->img, x, y, color); // put the pixel
}

void	draw_floor_ceiling(t_struct *game, int ray, int t_pix, int b_pix)	// draw the floor and the ceiling
{
	int		i;
	int		c;

	i = b_pix;
	while (i < S_H)
		my_game_pixel_put(game, ray, i++, 0xB99470FF); // floor
	i = 0;
	while (i < t_pix)
		my_game_pixel_put(game, ray, i++, 0x89CFF3FF); // ceiling
}

int	get_color(t_struct *game, int flag)	// get the color of the wall
{
	game->ray->ray_angle = nor_angle(game->ray->ray_angle); // normalize the angle
	if (flag == 0)
	{
		if (game->ray->ray_angle > M_PI / 2 && game->ray->ray_angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF); // west wall
		else
			return (0xB5B5B5FF); // east wall
	}
	else
	{
		if (game->ray->ray_angle > 0 && game->ray->ray_angle < M_PI)
			return (0xF5F5F5FF); // south wall
		else
			return (0xF5F5F5FF); // north wall
	}
}

void	draw_wall(t_struct *game, int ray, int t_pix, int b_pix)	// draw the wall
{
	int color;

	color = get_color(game, game->ray->flag);
	while (t_pix < b_pix)
		my_game_pixel_put(game, ray, t_pix++, color);
}

void	render_wall(t_struct *game, int ray, float distance)	// render the wall
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	distance *= cos(nor_angle(game->ray->ray_angle - game->ray->player_angle)); // fix the fisheye
	wall_h = (TILE_SIZE / distance) * ((S_W / 2) / tan(game->ray->fov_radians / 2)); // get the wall height
	b_pix = (S_H / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (S_H / 2) - (wall_h / 2); // get the top pixel
	if (b_pix > S_H) // check the bottom pixel
		b_pix = S_H;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	draw_wall(game, ray, t_pix, b_pix); // draw the wall
	draw_floor_ceiling(game, ray, t_pix, b_pix); // draw the floor and the ceiling
}