/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 20:51:59 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/04 13:28:36 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_fractal *frac)
{
	expose_hook(frac);
	// ft_bzero(frac->map->address, frac->map->bytes_per_line * frac->map->height);
	// mlx_clear_window(frac->map->connection, frac->map->window);
	// iteratePoints(frac->map, &scale2window, frac);
	// mlx_put_image_to_window(frac->map->connection, frac->map->window, frac->map->image, 0, 0);
}

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

void		start_conditions(t_fractal *frac, t_imaginary *c, t_imaginary *next, float x, float y)
{
	if (frac->type == 1 || frac->type == 3)
	{
		update_inum(c, x, y);
		update_inum(next, 0, 0);
	}
	else if (frac->type == 2 || frac->type == 4)
	{
		update_inum(c, frac->c.r, frac->c.i);
		update_inum(next, x, y);
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
	t_imaginary	old;

	frac = (t_fractal *)p;
	start_conditions(frac, &c, &next, x, y);
	i = 0;
	while (i < frac->maxIter)
	{
		if ((next.r * next.r) + (next.i * next.i) > 4)
		{
			//printf("Escaped at %f, %f\n", x, y);
			draw_pixel(frac->map, scale2window_x(frac, x), scale2window_y(frac, y), rgbtoi(color(i)));
			return(1);
		}
		fractal_iteration(frac->type, &old, &next, &c);
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
	frac->map = init_map(800, 800, "Fractal");
	frac->maxIter = 50;
	return (frac);
}
