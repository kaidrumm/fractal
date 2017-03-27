/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:50:51 by kdrumm            #+#    #+#             */
/*   Updated: 2017/03/27 15:16:32 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_imaginary
{
	double	r;
	double	i;
}				t_imaginary;

typedef struct	s_triple
{
	double	a;
	double	b;
	double	c;
}				t_triple;

typedef struct	s_fractal
{
	int			maxIter;
	int			type;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	t_imaginary	c;
	t_imaginary	next;
	t_imaginary	old;
}				t_fractal;

typedef struct	s_map
{
	void		*connection;
	void		*window;
	void		*image;
	char		*address;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			bytes_per_line;
	int			endian;
	t_fractal	*fractal;
}				t_map;

void		error(char *message);
void		mandelbrot(t_map *map);
int			expose_hook(t_map *map);
int			rgbtoi(t_triple *rgb);
void		mandelbrot(t_map *map);
void		julia(t_map *map, double cr, double ci);
void		cubic_mandelbrot(t_map *map);
void		cubic_julia(t_map *map, double cr, double ci);
void		fractal(t_map *map, int x, int y);
double		scale2window(int scale, int pixel);
void		fractal_iteration(int type, t_imaginary *old, t_imaginary *next, t_imaginary *c);
void		draw_pixel(t_map *map, int x, int y, int color);
void		init_fractal(t_map *map);
int			init_map(t_map **map, int w, int h, char *title);
int			check_range(double value, double min, double max, char *msg);
void		update_inum(t_imaginary *n, double a, double b);
void		update_triple(t_triple *abc, double x, double y, double z);
t_triple	*hsv2rgb(t_triple *hsv);
t_triple	*rgb2hsv(t_triple *rgb);
void		start_conditions(t_map *map, t_imaginary *c, t_imaginary *next, int x, int y);
void		iteratePoints(t_map *map);

#endif
