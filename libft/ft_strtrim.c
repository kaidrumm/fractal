/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:55:46 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/24 16:19:54 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MATCH(x) x == ' ' || x == '\n' || x == '\t'

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	head;
	size_t	tail;
	size_t	len;

	len = ft_strlen(s);
	head = 0;
	while (MATCH(s[head]))
		head++;
	if (head == len)
		return (ft_strdup(""));
	tail = 0;
	while (MATCH(s[len - tail - 1]))
		tail++;
	len = len - (head + tail);
	new = (char *)malloc(sizeof(char) * (len + 1));
	MALLOC_GUARD(new);
	new[len] = '\0';
	while (len-- > 0)
		new[len] = s[len + head];
	return (new);
}
