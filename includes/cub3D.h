/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:03:35 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/01 21:17:43 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "MLX42.h"
# include "msg.h"

# define SIZE = 35

typedef struct s_struct
{
	char	**map_2d;
}	t_struct;

void	validate_map(int argc, char **argv, t_struct *game);
char	**read_to_map(char *str);
int		safe_open(char *str);

#endif