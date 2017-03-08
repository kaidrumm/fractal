/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 14:02:07 by kdrumm            #+#    #+#             */
/*   Updated: 2016/09/23 14:27:06 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
	{
		ft_putstr_fd("null pointer", fd);
		return ;
	}
	if (ft_strlen(s) == 0)
		return ;
	else
		write(fd, s, ft_strlen(s));
}
