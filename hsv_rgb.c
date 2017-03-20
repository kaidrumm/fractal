/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:12:56 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/03/20 10:43:09 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(char *s)
{
	printf("%s", s);
	exit(1);
}

t_rgb	*hsv2rgb(t_hsv *hsv)
{
	t_rgb	*rgb;
	double	fract;
	double	p;
	double	q;
	double	t;
	int		sextant;

	rgb = (t_rgb *)malloc(sizeof(rgb));
	if (hsv->s == 0)
	{
		if (hsv->h == -1)
		{
			rgb->r = hsv->v;
			rgb->g = hsv->v;
			rgb->b = hsv->v;
		}
		else
			error("Invalid HSV value\n");
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
		{
			rgb->r = hsv->v;
			rgb->g = t;
			rgb->b = p;
		}
		else if (sextant == 1)
		{
			rgb->r = q;
			rgb->g = hsv->v;
			rgb->b = p;
		}
		else if (sextant == 2)
		{
			rgb->r = p;
			rgb->g = hsv->v;
			rgb->b = t;
		}
		else if (sextant == 3)
		{
			rgb->r = p;
			rgb->g = q;
			rgb->b = hsv->v;
		}
		else if (sextant == 4)
		{
			rgb->r = t;
			rgb->g = p;
			rgb->b = hsv->v;
		}
		else if (sextant == 5)
		{
			rgb->r = hsv->v;
			rgb->g = p;
			rgb->b = q;
		}
		else
			error("Invalid sextant\n");
	}
	return(rgb);
}

t_hsv	*rgb2hsv(t_rgb *rgb)
{
	t_hsv	*hsv;
	double	max;
	double	min;
	double	d;

	hsv = (t_hsv *)malloc(sizeof(hsv));
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
			error("Hue out of bounds\n");
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

	rgb = (t_rgb *)malloc(sizeof(rgb));

	if (atoi(av[1]) == 1) //rgb to hsv
	{
		rgb->r = atof(av[2])/(double)255;
		rgb->g = atof(av[3])/(double)255;
		rgb->b = atof(av[4])/(double)255;
		printf("Red: %f Green: %f Blue: %f\n", rgb->r, rgb->g, rgb->b);
		hsv = rgb2hsv(rgb);
		printf("Hue: %f Sat: %f Val: %f\n", hsv->h, hsv->s, hsv->v);
	}

	return (ac);
}