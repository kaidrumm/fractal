/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:49:57 by kdrumm            #+#    #+#             */
/*   Updated: 2017/03/20 18:56:44 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	complex_plane(t_map *map, t_pt *pt)
{
	pt->real = (4 / (double)(map->width)) * (double)(pt->x - (map->width / 2));
	pt->imaginary = (4 / (double)(map->width)) * (double)(pt->y - (map->height / 2));
}

int		expose_hook(t_map *map)
{
	mlx_clear_window(map->connection, map->window);
	mlx_put_image_to_window(map->connection, map->window, map->image, 0, 0);
	return (1);
}

int		rgbtoi(t_triple *rgb)
{
	int		r;
	int		b;
	int		g;

	r = (int)round(rgb->a);
	g = (int)round(rgb->b);
	b = (int)round(rgb->c);
	if (rgb->a < 1 && rgb->b < 1 && rgb->c < 1)
	{
		r = (int)round(rgb->a * 255);
		g = (int)round(rgb->b * 255);
		b = (int)round(rgb->c * 255);
	}
	return ((r * 0x10000) + (g * 0x100) + b);
}

void	mandelbrot_iteration(t_map *map, t_pt *pt)
{
	int			i;
	double		c_real;
	double		c_imaginary;
	double		new_real;
	double		new_imaginary;
	double		old_real;
	double		old_imaginary;
	t_triple	*hsv;
	t_triple	*rgbcolor;

	hsv = (t_triple *)malloc(sizeof(*hsv));
	if (!hsv)
		ft_error("Malloc error in mandelbrot_iteration");
	c_real = (double)pt->real;
	c_imaginary = (double)pt->imaginary;
	new_real = 0;
	new_imaginary = 0;
	i = 0;
	while (i < map->fractal->maxIterations)
	{
		old_real = new_real;
		old_imaginary = new_imaginary;
		new_real = old_real * old_real - old_imaginary * old_imaginary + c_real;
		new_imaginary = 2 * old_real * old_imaginary + c_imaginary;
		if (new_real * new_real + new_imaginary * new_imaginary > 4)
			ft_error("Final value out of bounds");
		i++;
	}
	hsv->a = i % 360;
	hsv->b = 1;
	hsv->c = 1 * (i < map->fractal->maxIterations);
	printf("final value of %f + %fi\n", new_real, new_imaginary);
	rgbcolor = hsv2rgb(hsv);
	draw_pixel(map, pt->x, pt->y, rgbtoi(rgbcolor));
}

/*
** Can be used to apply any function to ever dot on the map
*/

void	iteratePoints(t_map *map, void (*f)(t_map *, t_pt *))
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			f(map, map->dots[i][j]);
			j++;
		}
		i++;
	}
}

void	mandelbrot(t_map *map)
{
	map->fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!(map->fractal))
		ft_error("Malloc failure in mandelbrot");
	iteratePoints(map, &complex_plane);
	map->fractal->maxIterations = 200;
	iteratePoints(map, &mandelbrot_iteration);
}

/*
** Call init_map and then fractol types depending on input parameter
*/

int		main(void)
{
	t_map	*map;
	// double	a;
	// double	b;
	// double	c;

	// a = 4.2;
	// b = .42;
	// c = 24.24242;
	// printf("Maximum of %f, %f, %f is %f\n", a, b, c, maximum_doubles(3, a, b, c));

	init_map(&map, 400, 400, "Mandelbrot");
	mandelbrot(map);
	while (1)
	{
		expose_hook(map);
		//mlx_key_hook(map->window, key_hook, map);
		//mlx_mouse_hook(map->window, mouse_hook, map);
		mlx_loop(map->connection);
	}
	return (0);
}