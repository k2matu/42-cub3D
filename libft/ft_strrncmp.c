/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 07:44:19 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/11/04 16:46:18 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (s1[i] - s2[i]);
	len_s1 = ft_strlen(s1) - 1;
	len_s2 = ft_strlen(s2) - 1;
	while (s1[len_s1] == ' ')
		len_s1--;
	while ((n != 0 && len_s1 != 0) || (n != 0 && len_s2 != 0))
	{
		if ((unsigned char)s1[len_s1] != (unsigned char)s2[len_s2])
			return ((unsigned char)s1[len_s1] - (unsigned char)s2[len_s2]);
		n--;
		len_s1--;
		len_s2--;
	}
	return (0);
}
