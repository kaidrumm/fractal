/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:51:46 by marvin            #+#    #+#             */
/*   Updated: 2016/10/17 15:51:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_r(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstc;
	char	*srcc;

	i = 0;
	dstc = (char *)dst;
	srcc = (char *)src;
	while (n > 0)
	{
		dstc[n - 1] = srcc[n - 1];
		n--;
	}
	return (dst);
}
