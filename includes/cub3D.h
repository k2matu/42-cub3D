/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:03:35 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/05 11:36:41 by kmatjuhi         ###   ########.fr       */
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

# define SIZE = 35

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_texture;

typedef struct s_struct
{
	char		**map;
	t_texture	texture;
}	t_struct;

void	validate_map(int argc, char **argv, t_struct *game);
char	**read_to_map(char *str);
char	**arr_pop(char **old_arr, int row);
void	save_info(t_struct *game);
void	free_texture(t_texture texture);

// SAFE FUNCTIONS
int		safe_open(char *str);
ssize_t	safe_read(int fd, char *dest, ssize_t size, bool is_malloced);

#endif
