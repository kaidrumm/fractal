/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:20:05 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/24 11:51:19 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		usage(void)
{
	ft_error("Usage: ./fractol f where f=1 for Mandelbrot, f=2 for Julia, \
		f=3 for cubic mandelbrot, f=4 for cubic Julia, and f=5 for \
		Burningship.\n");
}

int			loop(t_fractal *frac)
{
	expose_hook(frac);
	mlx_key_hook(frac->map->window, key_hook, frac);
	mlx_mouse_hook(frac->map->window, mouse_hook, frac);
	if (frac->type == 2 || frac->type == 4)
		mlx_hook(frac->map->window, 6, 0, mouse_move, frac);
	mlx_loop(frac->map->connection);
	return (0);
}

static char	*set_name(int type)
{
	if (type == 1)
		return ("Mandelbrot");
	else if (type == 2)
		return ("Julia");
	else if (type == 3)
		return ("Cubic Mandelbrot");
	else if (type == 4)
		return ("Cubic Julia");
	else if (type == 5)
		return ("Burningship");
	return ("");
}

static int	child_actions(t_fractal *frac, char *av)
{
	int		type;

	type = atoi(av);
	if (type < 1 || type > 5)
		usage();
	init_fractal(frac, type);
	frac->map = init_map(800, 800, set_name(type));
	loop(frac);
	return (0);
}

/*
** Call init_map and then fractol types depending on input parameter
*/

int			main(int ac, char **av)
{
	t_fractal	frac;
	int			i;
	int			fork_id;

	if (ac < 2)
		usage();
	i = 1;
	while (av[i])
	{
		fork_id = fork();
		if (fork_id == 0)
			return (child_actions(&frac, av[i]));
		else if (fork_id == -1)
			ft_error("Error spawning windows\n");
		else
			i++;
	}
	while (i-- > 0)
		wait(NULL);
	return (0);
}
