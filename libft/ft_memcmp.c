/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:21:12 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/26 14:21:13 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1c;
	char	*s2c;

	i = 0;
	s1c = (char *)s1;
	s2c = (char *)s2;
	while (i < n)
	{
		if (s1c[i] == s2c[i])
			i++;
		else
			return ((unsigned char)s1c[i] - (unsigned char)s2c[i]);
	}
	return (0);
}
