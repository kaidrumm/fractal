/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:20:05 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/24 12:09:32 by kdrumm           ###   ########.fr       */
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
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_fractal
{
	int			max_iter;
	int			type;
	float		width;
	float		height;
	float		x_offset;
	float		y_offset;
	float		zoom;
	int			color_mode;
	int			color_offset;
	int			freeze;
	t_imaginary	c;
	t_imaginary	next;
	t_imaginary	old;
	t_map		*map;
}				t_fractal;

void			init_fractal(t_fractal *frac, int type);
int				color(float i, t_fractal *frac);
void			draw(t_fractal *frac);
int				expose_hook(t_fractal *frac);
int				scale2view(void *p, int x, int y);
int				key_hook(int keycode, t_fractal *frac);
int				fractal(void *frac, float x, float y);
void			zoom_in(t_fractal *frac, float x, float y);
void			zoom_out(t_fractal *frac, float x, float y);
int				scale2window_x(t_fractal *frac, float x);
int				scale2window_y(t_fractal *frac, float y);
void			translate(float delta_x, float delta_y);
int				mouse_move(int x, int y, t_fractal *frac);
int				mouse_hook(int button, int x, int y, t_fractal *frac);
t_imaginary		fractal_iteration(int type, t_imaginary old, t_imaginary sq,
	t_imaginary c);
void			start_conditions(t_fractal *frac, t_imaginary *next,
	float x, float y);

#endif
