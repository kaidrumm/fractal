/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:12:56 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/03/20 17:38:12 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_rgb(t_rgb *rgb, double x, double y, double z)
{
	rgb->r = x;
	rgb->g = y;
	rgb->b = z;
}

int		check_rgb(t_rgb *rgb)
{
	if (rgb->r < 0 || rgb->r > 1)
		ft_error("Invalid red");
	if (rgb->g < 0 || rgb->g > 1)
		ft_error("Invalid green");
	if (rgb->b < 0 || rgb->b > 1)
		ft_error("Invalid blue");
	return (0);
}

void	update_hsv(t_hsv *hsv, double x, double y, double z)
{
	hsv->h = x;
	hsv->s = y;
	hsv->v = z;
}

int		check_hsv(t_hsv *hsv)
{
	if (hsv->h < 0 || hsv->h > 360)
		ft_error("Invalid hue");
	if (hsv->s < 0 || hsv->s > 1)
		ft_error("Invalid saturation");
	if (hsv->v < 0 || hsv->v > 1)
		ft_error("Invalid value");
	return (0);
}

t_rgb	*hsv2rgb(t_hsv *hsv)
{
	t_rgb	*rgb;
	double	fract;
	double	p;
	double	q;
	double	t;
	int		sextant;

	check_hsv(hsv);
	rgb = (t_rgb *)malloc(sizeof(rgb));
	if (hsv->s == 0)
	{
		if (hsv->h == -1)
			update_rgb(rgb, hsv->v, hsv->v, hsv->v);
		else
			ft_error("Invalid HSV value\n");
	}
	else
	{
		if (hsv->h == 360)
			hsv->h = 0;
		else
			hsv->h = hsv->h / 60;
		sextant = floor(hsv->h);
		fract = hsv->h - sextant;
		p = hsv->v * (1 - hsv->s);
		q = hsv->v * (1 - (hsv->s * fract));
		t = hsv->v * (1 - (hsv->s * (1 - fract)));
		if (sextant == 0)
			update_rgb(rgb, hsv->v, t, p);
		else if (sextant == 1)
			update_rgb(rgb, q, hsv->v, p);
		else if (sextant == 2)
			update_rgb(rgb, p, hsv->v, t);
		else if (sextant == 3)
			update_rgb(rgb, p, q, hsv->v);
		else if (sextant == 4)
			update_rgb(rgb, t, p, hsv->v);
		else if (sextant == 5)
			update_rgb(rgb, hsv->v, p, q);
		else
			ft_error("Invalid sextant\n");
	}
	return (rgb);
}

t_hsv	*rgb2hsv(t_rgb *rgb)
{
	t_hsv	*hsv;
	double	max;
	double	min;
	double	d;

	check_rgb(rgb);
	hsv = (t_hsv *)malloc(sizeof(*hsv));
	max = maximum_doubles(3, rgb->r, rgb->g, rgb->b);
	min = minimum_doubles(3, rgb->r, rgb->g, rgb->b);
	printf("Max: %f, Min: %f\n", max, min);
	hsv->v = max;
	if (max == 0)
		hsv->s = 0;
	else
		hsv->s = (max - min) / max;
	if (hsv->s == 0)
		hsv->h = -1;
	else
	{
		d = max - min;
		if (rgb->r == max)
			hsv->h = (rgb->g - rgb->b) / d;
		else if (rgb->g == max)
			hsv->h = 2 + (rgb->b - rgb->r) / d;
		else if (rgb->b == max)
			hsv->h = 4 + (rgb->r - rgb->g) / d;
		else
			ft_error("Hue out of bounds\n");
		hsv->h = 60 * hsv->h;
		if (hsv->h < 0)
			hsv->h = hsv->h + 360;
	}
	return (hsv);
}

int		main(int ac, char **av)
{
	t_rgb	*rgb;
	t_hsv	*hsv;

	if (ac != 5)
		ft_error("Usage: <program name> <1: rgb->hsv or 2: hsv->rgb> <value value value>\n");
	if (atoi(av[1]) == 1) 
	{
		rgb = (t_rgb *)malloc(sizeof(*rgb));
		if (!rgb)
			ft_error("Malloc error in main\n");
		update_rgb(rgb, atof(av[2])/255, atof(av[3])/255, atof(av[4])/255);
		printf("Red: %f Green: %f Blue: %f\n", rgb->r, rgb->g, rgb->b);
		hsv = rgb2hsv(rgb);
		printf("Hue: %f Sat: %f Val: %f\n", hsv->h, hsv->s, hsv->v);
	}
	else if (atoi(av[1]) == 2)
	{
		hsv = (t_hsv *)malloc(sizeof(*hsv));
		if (!hsv)
			ft_error("Malloc error in main\n");
		update_hsv(hsv, atof(av[2]), atof(av[3]), atof(av[4]));
		printf("Hue: %f Saturation: %f Value: %f\n", hsv->h, hsv->s, hsv->v);
		rgb = hsv2rgb(hsv);
		printf("Red: %f Green: %f Blue: %f\n", rgb->r, rgb->g, rgb->b);
	}
	return (0);
}