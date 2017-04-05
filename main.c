/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:49:57 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/04 12:28:43 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractal *frac)
{
	frac->type = 1;
	// frac->c.r = 0;
	// frac->c.r = 0;
}

void	julia(t_fractal *frac, float cr, float ci)
{
	frac->type = 2;
	frac->c.r = cr;
	frac->c.i = ci;
}

void	cubic_mandelbrot(t_fractal *frac)
{
	frac->type = 3;
	// frac->c.r = 0;
	// frac->c.i = 0;
}

void	cubic_julia(t_fractal *frac, float cr, float ci)
{
	frac->type = 4;
	frac->c.r = cr;
	frac->c.i = ci;
}

/*
** Call init_map and then fractol types depending on input parameter
*/

int		main(int ac, char **av)
{
	t_fractal	*frac;
	int			type;

	if (ac < 2)
		ft_error("Usage: [./fractol 1] = Mandelbrot, [./fractol 2 {Cr, Ci}] = Julia\n");
	type = atoi(av[1]);
	frac = init_fractal();
	if (type == 1)
		mandelbrot(frac);
	else if (type == 2 && ac == 4)
		julia(frac, atof(av[2]), atof(av[3]));
	else if (type == 3)
		cubic_mandelbrot(frac);
	else if (type == 4 && ac == 4)
		cubic_julia(frac, atof(av[2]), atof(av[3]));
	else
		ft_error("Usage: [./fractol 1] = Mandelbrot, [./fractol 2 {Cr, Ci}] = Julia\n");
	frac->x_min = -2;
	frac->y_min = -2;
	frac->x_max = 2;
	frac->y_max = 2;
	frac->x_offset = -2;
	frac->y_offset = -2;
	expose_hook(frac);
	mlx_key_hook(frac->map->window, key_hook, frac);
	mlx_mouse_hook(frac->map->window, mouse_hook, frac);
	if (type == 2 || type == 4)
		mlx_hook(frac->map->window, 6, 0, mouse_move, frac);
	mlx_loop(frac->map->connection);
	return (0);
}
