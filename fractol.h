/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:50:51 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/03 19:04:01 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "libvisual/libvisual.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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
	t_map		*map;
}				t_fractal;

t_fractal		*init_fractal();
t_triple		*color(double i);
void			mandelbrot(t_fractal *frac);
void			mandelbrot(t_fractal *frac);
int				expose_hook(t_fractal *frac);
void			cubic_mandelbrot(t_fractal *frac);
double			scale2window(int scale, int pixel);
int				key_hook(int keycode, t_fractal *frac);
int				fractal(void *frac, int x, int y);
int				mouse_move(int x, int y, t_fractal *frac);
void			julia(t_fractal *frac, double cr, double ci);
void			cubic_julia(t_fractal *frac, double cr, double ci);
int				mouse_hook(int button, int x, int y, t_fractal *frac);
void			fractal_iteration(int type, t_imaginary *old, t_imaginary *next, t_imaginary *c);
void			start_conditions(t_fractal *frac, t_imaginary *c, t_imaginary *next, int x, int y);

#endif
