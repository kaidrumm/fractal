/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:55:40 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/27 13:55:41 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	MALLOC_GUARD(result);
	result[len] = '\0';
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
	{
		result[i] = s2[len];
		i++;
		len++;
	}
	return (result);
}
