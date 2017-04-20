/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 20:51:59 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/18 22:29:48 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This takes care of the actual math which, when repeated, determines if a
** point lies inside or outside of the fractal set.
*/

t_imaginary	fractal_iteration(int type, t_imaginary old, t_imaginary sq, 
	t_imaginary c)
{
	t_imaginary abs;
	t_imaginary next;
	t_imaginary cube;

	next.r = 0;
	if (type == 1 || type == 2)
	{
		next.r = sq.r - sq.i + c.r;
		next.i = 2 * old.r * old.i + c.i;
	}
	else if (type == 3 || type == 4)
	{
		cube.r = pow(old.r, 3);
		cube.i = pow(old.i, 3);
		next.r = cube.r - 3 * old.r * sq.i + c.r;
		next.i = c.i + 3 * sq.r * old.i - cube.i;
	}
	else if (type == 5)
	{
		abs.r = fabsf(old.r);
		abs.i = fabsf(old.i);
		next.r = sq.r - sq.i + c.r;
		next.i = 2 * abs.i * abs.r + c.i;	
	}
	return (next);
}

void		start_conditions(t_fractal *frac, t_imaginary *c,
	t_imaginary *next, float x, float y)
{
	if (frac->type == 1 || frac->type == 3 || frac->type == 5)
	{
		c->r = x;
		c->i = y;
		next->r = 0;
		next->i = 0;
	}
	else if (frac->type == 2 || frac->type == 4)
	{
		c->r = frac->c.r;
		c->i = frac->c.i;
		next->r = x;
		next->i = y;
	}
}

/*
** Template for all 3 fractal types 
*/

int			fractal(void *p, float x, float y)
{
	t_fractal	*frac;
	int			i;
	t_imaginary c;
	t_imaginary	next;
	t_imaginary	sq;

	frac = (t_fractal *)p;
	start_conditions(frac, &c, &next, x, y);
	i = 0;
	while (i < frac->maxIter)
	{
		sq.r = next.r * next.r;
		sq.i = next.i * next.i;
		if (sq.r + sq.i > 4)
		{
			draw_pixel(frac->map, scale2window_x(frac, x),
				scale2window_y(frac, y), color(i, frac));
			return (1);
		}
		next = fractal_iteration(frac->type, next, sq, c);
		i++;
	}
	draw_pixel(frac->map, x, y, 0x000000);
	return (1);
}

void		init_fractal(t_fractal *frac, int type)
{
	frac->maxIter = 42;
	frac->x_offset = -2;
	frac->y_offset = -2;
	frac->width = 4;
	frac->height = 4;
	frac->zoom = 1;
	frac->type = type;
	frac->color_mode = 0;
	frac->color_offset = 0;
	frac->freeze = 0;
}
