/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 22:55:24 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/24 16:00:39 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	MALLOC_GUARD(s2);
	while (i < size && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	while (i < size)
	{
		s2[i] = '\0';
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
