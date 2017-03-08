/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 21:14:29 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/05 21:14:29 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate a fresh link
** content and content_size must be copied from the parameters
** if content is null, content_size should be zero
** next is init as null
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	MALLOC_GUARD(new);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content_size = content_size;
		new->content = malloc(content_size);
		new->content = ft_memcpy(new->content, content, content_size);
		if (ft_memcmp(content, new->content, content_size) != 0)
		{
			free(new->content);
			free(new);
			return (NULL);
		}
	}
	new->next = NULL;
	return (new);
}
