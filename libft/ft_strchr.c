/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:11:55 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/05 15:25:32 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	unsigned char	a;
	int				i;

	a = c;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != a)
		i++;
	if (str[i] == a)
	{
		i++;
		return (&str[i]);
	}
	return (NULL);
}
