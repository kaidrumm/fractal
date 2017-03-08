/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:15:28 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/26 14:15:29 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*dstc;
	unsigned char	*srcc;

	i = 0;
	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		dstc[i] = srcc[i];
		if (dstc[i] == ch)
			return (&dstc[i + 1]);
		i++;
	}
	return (NULL);
}
