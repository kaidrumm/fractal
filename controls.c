/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 20:48:50 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/03 19:03:59 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	translate(double delta_x, double delta_y)
{
	printf("translate by %f, %f\n", delta_x, delta_y);
	return ;
}

/*
**
*/

void	zoom(double percent)
{
	printf("Zoom to %f\n", percent);
	return ;
}

/*
** Take the pixel measured from 0 to W/H and scale it to the map area from
** -2 to +2 by centering (subtracting half the scale) and multiplying by 4/scale
*/

double	scale2window(int scale, int pixel)
{
	//printf("Scale to window\n");
	return ((4 / (double)scale) * (double)(pixel - (scale / 2)));
}
