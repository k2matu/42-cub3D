/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:03:35 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/06 12:57:04 by kmatjuhi         ###   ########.fr       */
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

typedef struct s_element
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_element;

typedef struct s_struct
{
	char		**map;
	char		*content;
	t_element	element;
}	t_struct;

// PARSE
void	validate_file_content(int argc, char **argv, t_struct *game);
char	**save_file_content(t_struct *game, char *str);
void	save_info(t_struct *game, char **content2d);
char	**arr_pop(char **old_arr, int row);
void	free_elements(t_element element);
void	validate_map_content(char **map);

// SAFE_FUNC
int		safe_open(char *str);
ssize_t	safe_read(int fd, char *dest, ssize_t size, bool is_malloced);

#endif
