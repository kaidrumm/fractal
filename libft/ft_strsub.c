/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:55:33 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/27 13:55:34 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	MALLOC_GUARD(new);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[len] = '\0';
	return (new);
}
