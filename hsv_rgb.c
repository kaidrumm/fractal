/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:12:56 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/03/20 18:09:19 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		update_triple(t_triple *abc, double x, double y, double z)
{
	abc->a = x;
	abc->b = y;
	abc->c = z;
}

int			check_range(double value, double min, double max, char *msg)
{
	if (value < min || value > max)
		ft_error(msg);
	return (0);
}

int			check_rgb(t_triple *rgb)
{
	check_range(rgb->a, 0, 1, "Invalid red");
	check_range(rgb->c, 0, 1, "Invalid green");
	check_range(rgb->c, 0, 1, "Invalid blue");
	return (0);
}

int			check_hsv(t_triple *hsv)
{
	check_range(hsv->a, 0, 360, "Invalid hue");
	check_range(hsv->b, 0, 1, "Invalid saturation");
	check_range(hsv->c, 0, 1, "Invalid value");
	return (0);
}

t_triple	*hsv2rgb(t_triple *hsv)
{
	t_triple	*rgb;
	double		fract;
	t_triple	cmy;
	int			sextant;

	check_hsv(hsv);
	rgb = (t_triple *)malloc(sizeof(*rgb));
	if (hsv->b == 0)
	{
		if (hsv->a == -1)
			update_triple(rgb, hsv->c, hsv->c, hsv->c);
		else
			ft_error("Invalid HSV value\n");
	}
	else
	{
		if (hsv->a == 360)
			hsv->a = 0;
		else
			hsv->a = hsv->a / 60;
		sextant = floor(hsv->a);
		fract = hsv->a - sextant;
		cmy.a = hsv->c * (1 - hsv->b);
		cmy.b = hsv->c * (1 - (hsv->b * fract));
		cmy.c = hsv->c * (1 - (hsv->b * (1 - fract)));
		if (sextant == 0)
			update_triple(rgb, hsv->c, cmy.c, cmy.a);
		else if (sextant == 1)
			update_triple(rgb, cmy.b, hsv->c, cmy.a);
		else if (sextant == 2)
			update_triple(rgb, cmy.a, hsv->c, cmy.c);
		else if (sextant == 3)
			update_triple(rgb, cmy.a, cmy.b, hsv->c);
		else if (sextant == 4)
			update_triple(rgb, cmy.c, cmy.a, hsv->c);
		else if (sextant == 5)
			update_triple(rgb, hsv->c, cmy.a, cmy.b);
		else
			ft_error("Invalid sextant\n");
	}
	return (rgb);
}

t_triple	*rgb2hsv(t_triple *rgb)
{
	t_triple	*hsv;
	double		max;
	double		min;
	double		d;

	check_rgb(rgb);
	hsv = (t_triple *)malloc(sizeof(*hsv));
	max = maximum_doubles(3, rgb->a, rgb->c, rgb->c);
	min = minimum_doubles(3, rgb->a, rgb->c, rgb->c);
	printf("Max: %f, Min: %f\n", max, min);
	hsv->c = max;
	if (max == 0)
		hsv->b = 0;
	else
		hsv->b = (max - min) / max;
	if (hsv->b == 0)
		hsv->a = -1;
	else
	{
		d = max - min;
		if (rgb->a == max)
			hsv->a = (rgb->c - rgb->c) / d;
		else if (rgb->c == max)
			hsv->a = 2 + (rgb->c - rgb->a) / d;
		else if (rgb->c == max)
			hsv->a = 4 + (rgb->a - rgb->c) / d;
		else
			ft_error("Hue out of bounds\n");
		hsv->a = 60 * hsv->a;
		if (hsv->a < 0)
			hsv->a = hsv->a + 360;
	}
	return (hsv);
}

int			main(int ac, char **av)
{
	t_triple	*rgb;
	t_triple	*hsv;

	if (ac != 5)
		ft_error("Usage: <program name> <1: rgb->hsv or 2: hsv->rgb> <value value value>\n");
	if (atoi(av[1]) == 1) 
	{
		rgb = (t_triple *)malloc(sizeof(*rgb));
		if (!rgb)
			ft_error("Malloc error in main\n");
		update_triple(rgb, atof(av[2])/255, atof(av[3])/255, atof(av[4])/255);
		printf("Red: %f Green: %f Blue: %f\n", rgb->a, rgb->c, rgb->c);
		hsv = rgb2hsv(rgb);
		printf("Hue: %f Sat: %f Val: %f\n", hsv->a, hsv->b, hsv->c);
	}
	else if (atoi(av[1]) == 2)
	{
		hsv = (t_triple *)malloc(sizeof(*hsv));
		if (!hsv)
			ft_error("Malloc error in main\n");
		update_triple(hsv, atof(av[2]), atof(av[3]), atof(av[4]));
		printf("Hue: %f Saturation: %f Value: %f\n", hsv->a, hsv->b, hsv->c);
		rgb = hsv2rgb(hsv);
		printf("Red: %f Green: %f Blue: %f\n", rgb->a, rgb->c, rgb->c);
	}
	return (0);
}