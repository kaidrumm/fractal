/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:58:29 by marvin            #+#    #+#             */
/*   Updated: 2016/10/17 16:13:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sorted(t_list *lst, int (*cmp)(void *, void *))
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (cmp(lst->content, lst->next->content) != 0)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

t_list		*ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*cur;
	t_list	*move;

	cur = lst;
	while (!is_sorted(lst, cmp))
	{
		if (cmp(cur->content, cur->next->content) != 0)
			cur = cur->next;
		else
		{
			move = ft_lstpop(cur);
			cur = lst;
			if (cmp(move->content, cur->content) != 0)
				ft_lstadd(&lst, move);
			else
			{
				while (cur->next && cmp(cur->content, move->content) == 0)
					cur = cur->next;
				ft_lstinsert(cur, move);
			}
		}
	}
	return (lst);
}
