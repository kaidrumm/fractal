/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:49:57 by kdrumm            #+#    #+#             */
/*   Updated: 2017/03/24 19:06:11 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	julia_iteration(t_map *map, int x, int y)
// {
// 	int			i;
// 	t_imaginary	c;
// 	t_imaginary	next;
// 	t_imaginary	old;
// 	t_triple	*hsv;

// 	if (!(hsv = (t_triple *)malloc(sizeof(*hsv))))
// 		ft_error("Malloc error in julia_iteration");
// 	update_inum(&c, map->fractal->c.r, map->fractal->c.i);
// 	printf("C is %f, %f\n", c.r, c.i);
// 	update_inum(&next, scale2window(map->width, x), scale2window(map->height, y));
// 	i = 0;
// 	while(i < map->fractal->maxIter)
// 	{
// 		update_inum(&old, next.r, next.i);
// 		update_inum(&next, (old.r * old.r) - (old.i * old.i) + c.r, (2 * old.r * old.i) + c.i);
// 		if (((next.r * next.r) + (next.i * next.i)) > 4)			
// 		{
// 			update_triple(hsv, ((double)i / (double)map->fractal->maxIter) * 360, 1, 1);
// 			//printf("Julia Iteration for %f, %f: i ended at %i, final value of %f + %fi, HSV of %f, %f, %f\n", c.r, c.i, i, next.r, next.i, hsv->a, hsv->b, hsv->c);
// 			draw_pixel(map, x, y, rgbtoi(hsv2rgb(hsv)));
// 			return ;
// 		}
// 		i++;
// 	}
// 	draw_pixel(map, x, y, 0x000000);
// }

// void	mandelbrot_iteration(t_map *map, int x, int y)
// {
// 	int			i;
// 	t_imaginary c;
// 	t_imaginary	next;
// 	t_imaginary	old;
// 	t_triple	*hsv;

// 	if (!(hsv = (t_triple *)malloc(sizeof(*hsv))))
// 		ft_error("Malloc error in mandelbrot_iteration");
// 	update_inum(&c, scale2window(map->width, x), scale2window(map->height, y));
// 	update_inum(&next, 0, 0);
// 	i = 0;
// 	while (i < map->fractal->maxIter)
// 	{
// 		update_inum(&old, next.r, next.i);
// 		update_inum(&next, (old.r * old.r) - (old.i * old.i) + c.r, (2 * old.r * old.i) + c.i);
// 		if (((next.r * next.r) + (next.i * next.i)) > 4)			
// 		{
// 			update_triple(hsv, ((double)i / (double)map->fractal->maxIter) * 360, 1, 1);
// 			printf("Mandelbrot Iteration for %f, %f: i ended at %i, final value of %f + %fi, HSV of %f, %f, %f\n", c.r, c.i, i, next.r, next.i, hsv->a, hsv->b, hsv->c);
// 			draw_pixel(map, x, y, rgbtoi(hsv2rgb(hsv)));
// 			return ;
// 		}
// 		i++;
// 	}
// 	draw_pixel(map, x, y, 0x000000);
// }

void	fractal_iteration(int type, t_imaginary *old, t_imaginary *next, t_imaginary *c)
{
	if (type == 1 || type == 2)
	{
		update_inum(old, next->r, next->i);
		update_inum(next, pow(old->r, 2) - pow(old->i, 2) + c->r, (2 * old->r * old->i) + c->i);
	}
	else if (type == 3)
	{
		update_inum(old, next->r, next->i);
		update_inum(next, pow(old->r, 3) - 3 * old->r * pow(old->i, 2) + c->r, c->i + 3 * pow(old->r, 2) * old->i - pow (old->i, 3));
	}
}

void	start_conditions(t_map *map, t_imaginary *c, t_imaginary *next, int x, int y)
{
	if (map->fractal->type == 1 || map->fractal->type == 3)
	{
		update_inum(c, scale2window(map->width, x), scale2window(map->height, y));
		update_inum(next, 0, 0);
	}
	else if (map->fractal->type == 2)
	{
		update_inum(c, map->fractal->c.r, map->fractal->c.i);
		printf("C is %f, %f\n", c->r, c->i);
		update_inum(next, scale2window(map->width, x), scale2window(map->height, y));
	}
}

/*
** Template for all 3 fractal types 
*/

void	fractal(t_map *map, int x, int y)
{
	int			i;
	t_triple	*hsv;
	t_imaginary c;
	t_imaginary	next;
	t_imaginary	old;

	if (!(hsv = (t_triple *)malloc(sizeof(*hsv))))
		ft_error("Malloc error in fractal_iteration");
	start_conditions(map, &c, &next, x, y);
	i = 0;
	while (i < map->fractal->maxIter)
	{
		fractal_iteration(map->fractal->type, &old, &next, &c);
		if ((next.r * next.r) + (next.i * next.i) > 4)
		{
			update_triple(hsv, ((double)i / (double)map->fractal->maxIter) * 360, 1, 1);
			printf("Iteration for %f, %f: i ended at %i, final value of %f + %fi, HSV of %f, %f, %f\n", c.r, c.i, i, next.r, next.i, hsv->a, hsv->b, hsv->c);
			draw_pixel(map, x, y, rgbtoi(hsv2rgb(hsv)));
			return ;
		}
		i++;
	}
	draw_pixel(map, x, y, 0x000000);
}

void	mandelbrot(t_map *map)
{
	map->fractal->type = 1;
	map->fractal->c.r = 0;
	map->fractal->c.r = 0;
	iteratePoints(map, &fractal);
}

void	julia(t_map *map, double cr, double ci)
{
	map->fractal->type = 2;
	map->fractal->c.r = cr;
	map->fractal->c.i = ci;
	iteratePoints(map, &fractal);
}

void	cubic(t_map *map)
{
	map->fractal->type = 3;
	// map->fractal->c.r = cr;
	// map->fractal->c.i = ci;
	iteratePoints(map, &fractal);
}

/*
** Call init_map and then fractol types depending on input parameter
*/

int		main(int ac, char **av)
{
	t_map	*map;

	if (ac < 2)
		ft_error("Usage: [./fractol 1] = Mandelbrot, [./fractol 2 {Cr, Ci}] = Julia\n");
	init_map(&map, 400, 400, "");
	init_fractal(map);
	if (atoi(av[1]) == 1)
	{
		printf("Mandelbrot\n");
		mandelbrot(map);
	}
	else if (atoi(av[1]) == 2 && ac == 4)
	{
		printf("Julia of %f, %f\n", atof(av[2]), atof(av[3]));
		julia(map, atof(av[2]), atof(av[3]));
	}
	else if (atoi(av[1]) == 3)
	{
		printf("Cubic Mandelbrot set\n");
		cubic(map);
	}
	else
	{
		ft_error("Usage: [./fractol 1] = Mandelbrot, [./fractol 2 {Cr, Ci}] = Julia\n");
		return (1);
	}
	while (1)
	{
		expose_hook(map);
		//mlx_key_hook(map->window, key_hook, map);
		//mlx_mouse_hook(map->window, mouse_hook, map);
		mlx_loop(map->connection);
	}
	return (0);
}