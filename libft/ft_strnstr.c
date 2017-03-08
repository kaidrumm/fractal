/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignbig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 14:04:13 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/23 14:04:14 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*does_match(const char *big, const char *little, int i)
{
	int		j;

	j = 0;
	while (little[j] != '\0')
	{
		if (big[i + j] == little[j])
			j++;
		else
			return (NULL);
	}
	return ((void *)&big[i]);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	void	*found;

	i = big[1];
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len >= ft_strlen(little))
	{
		while (big[i] && i <= len - ft_strlen(little))
		{
			if (big[i] == little[0])
			{
				found = does_match(big, little, i);
				if (found)
					return ((char *)found);
			}
			i++;
		}
	}
	return (NULL);
}
