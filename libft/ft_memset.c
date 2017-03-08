/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:34:57 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/21 13:34:58 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	ch;
	size_t			i;
	char			*word;

	word = str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		word[i] = ch;
		i++;
	}
	return (str);
}
