/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:49:57 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/02 21:57:50 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractal *frac)
{
	frac->type = 1;
	frac->c.r = 0;
	frac->c.r = 0;
}

void	julia(t_fractal *frac, double cr, double ci)
{
	frac->type = 2;
	frac->c.r = cr;
	frac->c.i = ci;
}

void	cubic_mandelbrot(t_fractal *frac)
{
	frac->type = 3;
}

void	cubic_julia(t_fractal *frac, double cr, double ci)
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

	if (ac < 2)
		ft_error("Usage: [./fractol 1] = Mandelbrot, [./fractol 2 {Cr, Ci}] = Julia\n");
	frac = init_fractal();
	if (atoi(av[1]) == 1)
		mandelbrot(frac);
	else if (atoi(av[1]) == 2 && ac == 4)
		julia(frac, atof(av[2]), atof(av[3]));
	else if (atoi(av[1]) == 3)
		cubic_mandelbrot(frac);
	else if (atoi(av[1]) == 4 && ac == 4)
		cubic_julia(frac, atof(av[2]), atof(av[3]));
	else
		ft_error("Usage: [./fractol 1] = Mandelbrot, [./fractol 2 {Cr, Ci}] = Julia\n");
	expose_hook(frac);
	mlx_key_hook(frac->map->window, key_hook, frac);
	mlx_mouse_hook(frac->map->window, mouse_hook, frac);
	mlx_loop(frac->map->connection);
	return (0);
}