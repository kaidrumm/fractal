/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:56:06 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/04/02 21:27:39 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

/*
** Essentially library functions
*/

int			check_range(double value, double min, double max, char *msg)
{
	if (value < min || value > max)
		ft_error(msg);
	return (0);
}

void		update_inum(t_imaginary *n, double a, double b)
{
	n->r = a;
	n->i = b;
}

void		update_triple(t_triple *abc, double x, double y, double z)
{
	abc->a = x;
	abc->b = y;
	abc->c = z;
}
