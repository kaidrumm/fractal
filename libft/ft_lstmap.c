/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 21:27:25 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/05 21:27:26 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*head;

	current = NULL;
	head = NULL;
	while (lst != NULL)
	{
		if (head == NULL)
		{
			head = f(lst);
			current = head;
			lst = lst->next;
		}
		else
		{
			current->next = f(lst);
			current = current->next;
			lst = lst->next;
		}
	}
	return (head);
}
