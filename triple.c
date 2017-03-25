/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:56:06 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/03/23 21:10:36 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			check_range(double value, double min, double max, char *msg)
{
	//printf("Check Range\n");
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
	//printf("Update Triple\n");
	abc->a = x;
	abc->b = y;
	abc->c = z;
}
