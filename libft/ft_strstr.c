/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:07:39 by kdrumm            #+#    #+#             */
/*   Updated: 2016/07/19 10:07:40 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*does_match(const char *big, const char *little, int i)
{
	char	*found;
	int		j;

	j = 0;
	found = (void *)&big[i];
	while (little[j] != '\0')
	{
		if (big[i] == little[j])
		{
			i++;
			j++;
		}
		else
			return (NULL);
	}
	return (found);
}

char			*ft_strstr(const char *big, const char *little)
{
	int		i;
	void	*found;

	i = 0;
	found = NULL;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			found = does_match(big, little, i);
			if (found)
				return (found);
		}
		i++;
	}
	return (found);
}
