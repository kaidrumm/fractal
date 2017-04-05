/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 20:48:50 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/04 12:46:35 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	translate(float delta_x, float delta_y)
{
	printf("translate by %f, %f\n", delta_x, delta_y);
	return ;
}

/*
**
*/

void	zoom(t_fractal *frac, float percent)
{
	printf("Zoom to %f in fractal %p\n", percent, frac);
	return ;
}

/*
** Take the pixel and scale it to the fractal math area
*/

int		scale2view(void *p, int x, int y)
{
	t_fractal	*frac;
	float		width;
	float		height;
	float		i;
	float		j;

	frac = (t_fractal *)p;
	width = frac->x_max - frac->x_min;
	height = frac->y_max - frac->y_min;
	i = (float)x / (float)frac->map->width;
	j = (float)y / (float)frac->map->height;
	i *= width;
	j *= height;
	i += frac->x_offset;
	j += frac->y_offset;
	//printf("%i, %i scaled to %f, %f\n", x, y, i, j);
	fractal(frac, i, j);
	return(0);
}

int		scale2window_x(t_fractal *frac, float x)
{
	int		pixel;
	float	width;

	x -= frac->x_offset;
	width = (float)(frac->x_max - frac->x_min);
	x /= width;
	x *= (float)frac->map->width;
	pixel = (int)roundf(x);
	return (pixel);
}

int		scale2window_y(t_fractal *frac, float y)
{
	int		pixel;
	float	height;

	y -= frac->y_offset;
	height = (float)(frac->y_max - frac->y_min);
	y /= height;
	y *= (float)frac->map->height;
	pixel = (int)roundf(y);
	return (pixel);
}
