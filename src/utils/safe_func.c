/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:27:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/01 10:02:41 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	safe_open(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Open file error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

ssize_t	safe_read(int fd, char *dest, ssize_t size, bool is_malloced)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, dest, size);
	if (bytes_read == -1 || (bytes_read != size && bytes_read != 0))
	{
		if (bytes_read == -1)
			perror("Read file error");
		else
			perror("Unexpected end of file");
		close(fd);
		if (is_malloced)
			free(dest);
		exit(EXIT_FAILURE);
	}
	return (bytes_read);
}
