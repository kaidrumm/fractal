/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:50:51 by kdrumm            #+#    #+#             */
/*   Updated: 2017/03/20 18:53:43 by kaidrumm         ###   ########.us       */
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

typedef struct	s_triple
{
	double	a;
	double	b;
	double	c;
}				t_triple;

typedef struct	s_fractal
{
	int			maxIterations;
}				t_fractal;

typedef struct	s_pt
{
	int		x;
	int		y;
	int		z;
	double	real;
	double	imaginary;
}				t_pt;

typedef struct	s_map
{
	void		*connection;
	void		*window;
	void		*image;
	char		*address;
	t_pt		***dots;
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
void		complex_plane(t_map *map, t_pt *pt);
void		draw_pixel(t_map *map, int x, int y, int color);
int			init_map(t_map **map, int w, int h, char *title);
t_triple	*hsv2rgb(t_triple *hsv);
t_triple	*rgb2hsv(t_triple *rgb);
void		mandelbrot_iteration(t_map *map, t_pt *pt);
void		iteratePoints(t_map *map, void (*f)(t_map *, t_pt *));

#endif
