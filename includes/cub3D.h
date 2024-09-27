/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:03:35 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/26 21:19:51 by kmatjuhi         ###   ########.fr       */
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

# define S_W 1900
# define S_H 1000
# define TILE_SIZE 30

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

typedef struct s_player_px {
	int		plyr_px_y;
	int		plyr_px_x;
	
}	t_player_px;

typedef struct s_struct
{
	char		**map;
	char		*content;
	int			row;
	int			col;
	t_element	elem;
	t_player	player;
	t_player_px	plyr_px;
	mlx_t		*mlx;
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

#endif
