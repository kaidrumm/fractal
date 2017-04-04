/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:59:36 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/03 20:30:32 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_triple	*color(float i)
{
	t_triple	*rgb;

	if (!(rgb = (t_triple *)malloc(sizeof(*rgb))))
		ft_error("Malloc error in color\n");
	rgb->a = sin(i);
	rgb->b = cos(i);
	rgb->c = -cos(i);
	rgb->a = rgb->a + 1;
	rgb->b = rgb->b + 1;
	rgb->c = rgb->c + 1;
	rgb->a = rgb->a * 127;
	rgb->b = rgb->b * 127;
	rgb->c = rgb->c * 127;
	//printf("Color of %f, %f, %f\n", rgb->a, rgb->b, rgb->c);
	return (rgb);
}
