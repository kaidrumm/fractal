/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:49:57 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/18 22:26:41 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		usage()
{
	ft_error("Usage: ./fractol f where f=1 for Mandelbrot, f=2 for Julia, \
		f=3 for cubic mandelbrot, f=4 for cubic Julia, and f=5 for \
		Burningship.\n");
}

/*
** Call init_map and then fractol types depending on input parameter
*/

int				main(int ac, char **av)
{
	t_fractal	*frac;
	int			type;

	if (ac != 2)
		usage();
	type = atoi(av[1]);
	if (type < 1 || type > 5)
		usage();
	frac = init_fractal(type);
	expose_hook(frac);
	mlx_key_hook(frac->map->window, key_hook, frac);
	mlx_mouse_hook(frac->map->window, mouse_hook, frac);
	if (type == 2 || type == 4)
		mlx_hook(frac->map->window, 6, 0, mouse_move, frac);
	mlx_loop(frac->map->connection);
	return (0);
}
