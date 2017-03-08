/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:02:11 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/24 15:59:00 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Needs to guarantee NULL-termination, and return a value to detect truncation.
** Do not zero-fill unsused bytes in the destination.
*/

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	i;

	i = 0;
	a = ft_strlen(src);
	b = ft_strnlen(dst, size);
	if (b >= size)
		return (a + size);
	while (b + i < size - 1 && src[i])
	{
		dst[b + i] = src[i];
		i++;
	}
	dst[b + i] = '\0';
	return (a + b);
}
