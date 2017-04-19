/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:50:51 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/18 22:23:37 by kaidrumm         ###   ########.us       */
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
	float		width;
	float		height;
	float		x_offset;
	float		y_offset;
	float		zoom;
	t_imaginary	c;
	t_imaginary	next;
	t_imaginary	old;
	t_map		*map;
}				t_fractal;

t_fractal		*init_fractal();
t_triple		*color(float i);
void			draw(t_fractal *frac);
int				expose_hook(t_fractal *frac);
int				scale2view(void *p, int x, int y);
int				key_hook(int keycode, t_fractal *frac);
int				fractal(void *frac, float x, float y);
void			zoom(t_fractal *frac, float percent);
int				scale2window_x(t_fractal *frac, float x);
int				scale2window_y(t_fractal *frac, float y);
void			translate(float delta_x, float delta_y);
int				mouse_move(int x, int y, t_fractal *frac);
int				mouse_hook(int button, int x, int y, t_fractal *frac);
void			fractal_iteration(int type, t_imaginary *old, t_imaginary *next, t_imaginary *c);
void			start_conditions(t_fractal *frac, t_imaginary *c, t_imaginary *next, float x, float y);

#endif
