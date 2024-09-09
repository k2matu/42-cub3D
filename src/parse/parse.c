/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:25:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/09/09 11:37:23 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse(int argc, char **argv, t_struct *game)
{
	char	**content2d;

	if (argc != 2 || ft_strrncmp(argv[1], ".cub", 4) != 0 || ft_strlen(argv[1]) < 5)
	{
		ft_putendl_fd(ERR_FILE_NOT_CUB, 2);
		exit(EXIT_FAILURE);
	}
	content2d = save_file_content(game, argv[1]);
	save_info(game, content2d);
	validate_elems(game);
	validate_map(game, game->map);

	free(game->content);
	ft_free_arr(game->map);
	free_elements(&(game->elem));
}
