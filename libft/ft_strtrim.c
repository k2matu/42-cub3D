/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 06:53:37 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/14 21:19:14 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	first_pos(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && match(set, s1[i]))
		i++;
	return (i);
}

static int	last_pos(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (i > 0 && match(set, s1[i - 1]))
		i--;
	return (i);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		first;
	int		last;
	int		len;
	char	*dest;

	first = first_pos(s1, set);
	last = last_pos(s1, set);
	len = last - first;
	if (len <= 0)
	{
		dest = (char *)malloc(sizeof(char) * 1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
	}
	else
		dest = ft_substr(s1, first, len);
	free(s1);
	return (dest);
}
