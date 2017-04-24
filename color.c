/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:20:05 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/24 11:38:22 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color(float i, t_fractal *frac)
{
	t_triple	rgb;
	float		fraction;

	fraction = i / (float)frac->max_iter;
	if (frac->color_mode == 0)
	{
		rgb.a = sinf(i);
		rgb.b = cosf(i);
		rgb.c = -cosf(i);
	}
	else if (frac->color_mode == 1)
	{
		rgb.a = sinf(fraction * M_PI - M_PI_2 + frac->color_offset);
		rgb.b = sinf(fraction * M_PI * 2 - M_PI_2 + frac->color_offset);
		rgb.c = sinf(fraction * M_PI * 4 - M_PI_2 + frac->color_offset);
	}
	rgb.a += 1;
	rgb.b += 1;
	rgb.c += 1;
	rgb.a *= 127;
	rgb.b *= 127;
	rgb.c *= 127;
	return (((int)round(rgb.a) * 0x10000) + ((int)round(rgb.b) * 0x100)
		+ (int)round(rgb.c));
}
