/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:16:31 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/10/29 20:08:27 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define ERR_MALLOC "Malloc failed"
# define ERR_CALLOC "Calloc failed"

# define ERR_FILE_NOT_CUB "Error\nNot a .cub file"
# define ERR_FILE_NOT_PNG "Error\nNot an .png file"
# define ERR_ELEM_MISSING "Error\nMissing element(s)"
# define ERR_ELEM_INVALID "Error\nInvalid element(s)"
# define ERR_MAP_CHAR "Error\nInvalid map character(s)"
# define ERR_PLAYER_COUNT "Error\nInvalid player count"
# define ERR_MAP_INVALID "Error\nInvalid map"
# define ERR_RGB_VAL "Error\nInvalid RGB value (min: 0, max: 255)"

# define ERR_MLX "Error\nFailed to initialize MLX42"
# define ERR_MLX_TEXTURE "Error\nMlx texture failed"

#endif