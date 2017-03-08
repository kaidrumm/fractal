/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:55:55 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/27 13:55:56 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**split_words(char *s, char c, int i, int n)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * (n + 1));
	MALLOC_GUARD(array);
	array[n] = NULL;
	i--;
	while (n)
	{
		n--;
		while (s[i] == c)
			i--;
		while (s[i] != c && i)
			i--;
		array[n] = ft_strtrimc(&s[i], c);
		MALLOC_GUARD(array[n]);
		s[i] = '\0';
		i--;
	}
	free(s);
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*scopy;
	int		n;
	int		i;

	if (!s || !c)
		return (NULL);
	n = 0;
	i = 0;
	scopy = NULL;
	scopy = ft_strdup(s);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		n++;
	}
	return (split_words(scopy, c, i, n));
}
