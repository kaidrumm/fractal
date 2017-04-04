/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:56:06 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/04/03 20:35:17 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

/*
** Essentially library functions
*/

int			check_range(float value, float min, float max, char *msg)
{
	if (value < min || value > max)
		ft_error(msg);
	return (0);
}

void		update_inum(t_imaginary *n, float a, float b)
{
	n->r = a;
	n->i = b;
}

void		update_triple(t_triple *abc, float x, float y, float z)
{
	abc->a = x;
	abc->b = y;
	abc->c = z;
}
