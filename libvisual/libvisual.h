/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvisual.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 21:15:50 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/02 22:14:40 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVISUAL_H
# define LIBVISUAL_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

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
}				t_map;

int				rgbtoi(t_triple *rgb);
t_triple		*rgb2hsv(t_triple *rgb);
t_triple		*hsv2rgb(t_triple *hsv);
int				check_hsv(t_triple *hsv);
int				check_rgb_fraction(t_triple *rgb);
void			update_inum(t_imaginary *n, double a, double b);
void			draw_pixel(t_map *map, int x, int y, int color);
t_map			*init_map(int w, int h, char *title);
void			update_triple(t_triple *abc, double x, double y, double z);
int				check_range(double value, double min, double max, char *msg);
void			iteratePoints(t_map *map, int (*f)(void	*p, int i, int j), void *p);

#endif
