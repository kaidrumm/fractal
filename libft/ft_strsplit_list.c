/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 22:40:27 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/08 22:40:28 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_strsplit_list(char const *s, char c)
{
	t_list	*list;
	size_t	i;

	if (!s || !c)
		return (NULL);
	i = 0;
	list = NULL;
	while (s[i])
	{
		while (s[i] == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		ft_lstaddb(&list, ft_lstnew(ft_strndup(s, i), i));
		s += i;
		i = 0;
	}
	return (list);
}
