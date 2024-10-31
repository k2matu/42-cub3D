/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibari <hzibari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:03:35 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/10/31 14:28:47 by hzibari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "MLX42.h"
# include "msg.h"
# include <math.h>

# define S_W 2000
# define S_H 1500
# define TILE_SIZE 30
# define FOV 60
# define MOVE_SPEED 0.9
# define M_PI 3.14159265358979323846

typedef struct s_element
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_element;

typedef struct s_player
{
	int		pos_y;
	int		pos_x;
	char	direction;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	player_angle;
	double	pixel_pos_x;
	double	pixel_pos_y;
	float	x_step;
	float	y_step;
	float	fov_radians;
	int		flag;
}	t_ray;

typedef struct s_struct
{
	char			**map;
	char			*content;
	int				row;
	int				col;
	t_element		elem;
	t_player		player;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_ray			*ray;
}	t_struct;

/* free_func.c */
void	clean_exit(t_struct *game, char *msg, char **arr);
void	free_elements(t_element *elem);

/* parse */
void	parse(int argc, char **argv, t_struct *game);
char	**save_file_content(t_struct *game, char *str);
void	save_info(t_struct *game, char **content2d);
char	**arr_pop(char **old_arr, int row);
void	validate_elems(t_struct *game);
void	validate_map(t_struct *game, char **map);
void	flood_fill(char **map, int x, int y, int row);
char	**ft_arrdup(char **arr);

/* safe_func */
int		safe_open(char *str);
ssize_t	safe_read(int fd, char *dest, ssize_t size, bool is_malloced);

/* safe_mlx */
mlx_t	*safe_mlx_init(t_struct *game);
void	safe_mlx_terminate(t_struct *game);

float	nor_angle(float angle);

/* ray funtions */
void	raycasting(t_struct *game);
void	fix_inters_for_y(t_struct *game, float *y_inter, float *x_inter);
void	fix_inters_for_x(t_struct *game, float *y_inter, float *x_inter);
int		check_wall_hit(t_struct *game, float x_inter, float y_inter);

/* fir the key press movements */
void	key_press(mlx_key_data_t keydata, void *param);

/* wall rendering */
void	render_wall(t_struct *mlx, int ray, float distance);

#endif
