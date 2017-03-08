/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 11:58:20 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/07 11:58:20 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Input must be a list containing only strings
*/

void	ft_lstprint(t_list *l)
{
	ft_putendl("\n**Printing List**");
	while (l)
	{
		if (l->content)
			ft_putendl((char *)l->content);
		else
			ft_putendl("Null node");
		l = l->next;
	}
	ft_putendl("**End of List**");
}
