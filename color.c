/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:59:36 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/03 19:03:59 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_triple	*color(double i)
{
	t_triple	*rgb;

	if (!(rgb = (t_triple *)malloc(sizeof(*rgb))))
		ft_error("Malloc error in color\n");
	rgb->a = sin(i) + 1;
	rgb->b = cos(i) + 1;
	rgb->c = -cos(i) + 1;
	rgb->a = rgb->a + 1;
	rgb->b = rgb->b + 1;
	rgb->c = rgb->c + 1;
	rgb->a = rgb->a * 127;
	rgb->b = rgb->b * 127;
	rgb->c = rgb->c * 127;
	//printf("Color of %f, %f, %f\n", rgb->a, rgb->b, rgb->c);
	return (rgb);
}
