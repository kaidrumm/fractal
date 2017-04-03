/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 20:51:59 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/02 22:17:32 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This takes care of the actual math which, when repeated, determines if a
** point lies inside or outside of the fractal set.
*/

void	fractal_iteration(int type, t_imaginary *old, t_imaginary *next, t_imaginary *c)
{
	if (type == 1 || type == 2)
	{
		update_inum(old, next->r, next->i);
		update_inum(next, pow(old->r, 2) - pow(old->i, 2) + c->r, (2 * old->r * old->i) + c->i);
	}
	else if (type == 3 || type == 4)
	{
		update_inum(old, next->r, next->i);
		update_inum(next, pow(old->r, 3) - 3 * old->r * pow(old->i, 2) + c->r, c->i + 3 * pow(old->r, 2) * old->i - pow (old->i, 3));
	}
}

/*
** This sets the inital calculation values where they differ between
** Mandelbrot and Julia sets.
*/

void		start_conditions(t_fractal *frac, t_imaginary *c, t_imaginary *next, int x, int y)
{
	if (frac->type == 1 || frac->type == 3)
	{
		update_inum(c, scale2window(frac->map->width, x), scale2window(frac->map->height, y));
		update_inum(next, 0, 0);
	}
	else if (frac->type == 2 || frac->type == 4)
	{
		update_inum(c, frac->c.r, frac->c.i);
		printf("C is %f, %f\n", c->r, c->i);
		update_inum(next, scale2window(frac->map->width, x), scale2window(frac->map->height, y));
	}
}

/*
** Template for all 3 fractal types 
*/

int			fractal(void *p, int x, int y)
{
	t_fractal	*frac;
	int			i;
	//double		percent;
	t_triple	*hsv;
	t_imaginary c;
	t_imaginary	next;
	t_imaginary	old;

	frac = (t_fractal *)p;
	if (!(hsv = (t_triple *)malloc(sizeof(*hsv))))
		ft_error("Malloc error in fractal_iteration");
	start_conditions(frac, &c, &next, x, y);
	i = 0;
	while (i < frac->maxIter)
	{
		fractal_iteration(frac->type, &old, &next, &c);
		if ((next.r * next.r) + (next.i * next.i) > 4)
		{
			//percent = (double)(i / (double)map->fractal->maxIter);
			draw_pixel(frac->map, x, y, rgbtoi(color(i)));
			//update_triple(hsv, ((double)i / (double)map->fractal->maxIter) * 360, 1, 1);
			//printf("Iteration for %f, %f: i ended at %i, final value of %f + %fi, HSV of %f, %f, %f\n", c.r, c.i, i, next.r, next.i, hsv->a, hsv->b, hsv->c);
			//draw_pixel(map, x, y, rgbtoi(hsv2rgb(hsv)));
			return(1);
		}
		i++;
	}
	draw_pixel(frac->map, x, y, 0x000000);
	return (1);
}

t_fractal	*init_fractal()
{
	t_fractal	*frac;

	if (!(frac = (t_fractal *)malloc(sizeof(t_fractal))))
		ft_error("Malloc failure initializing fractal");
	frac->map = init_map(400, 400, "");
	frac->maxIter = 500;
	return (frac);
}
