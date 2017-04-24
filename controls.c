/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:44:47 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/24 11:40:10 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractal *frac, float x, float y)
{
	frac->zoom *= 1.1;
	frac->width /= 1.1;
	frac->height /= 1.1;
	frac->x_offset = x - frac->width / 2;
	frac->y_offset = y - frac->height / 2;
	frac->max_iter += 5;
}

void	zoom_out(t_fractal *frac, float x, float y)
{
	frac->zoom /= 1.1;
	frac->width *= 1.1;
	frac->height *= 1.1;
	frac->x_offset = x - frac->width / 2;
	frac->y_offset = y - frac->height / 2;
	frac->max_iter -= 5;
}

/*
** Take the window coordinate and scale it to the fractal math area
*/

int		scale2view(void *p, int x, int y)
{
	t_fractal	*frac;
	float		i;
	float		j;

	frac = (t_fractal *)p;
	i = (float)x / (float)frac->map->width;
	j = (float)y / (float)frac->map->height;
	i *= frac->width;
	j *= frac->height;
	i += frac->x_offset;
	j += frac->y_offset;
	fractal(frac, i, j);
	return (0);
}

int		scale2window_x(t_fractal *frac, float x)
{
	int		pixel;

	x -= frac->x_offset;
	x /= frac->width;
	x *= (float)frac->map->width;
	pixel = (int)roundf(x);
	return (pixel);
}

int		scale2window_y(t_fractal *frac, float y)
{
	int		pixel;

	y -= frac->y_offset;
	y /= frac->height;
	y *= (float)frac->map->height;
	pixel = (int)roundf(y);
	return (pixel);
}
