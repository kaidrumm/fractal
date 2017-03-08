/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:19:54 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/26 14:19:55 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sc;
	unsigned char	ch;

	i = 0;
	sc = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (sc[i] == ch)
			return (&sc[i]);
		i++;
	}
	return (NULL);
}
