/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:12:56 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/03/14 20:16:40 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rbg	hsv2rgb(t_hsv hsv)
{
	t_rgb	rbg;
	double	fract;
	double	p;
	double	q;
	double	t;
	int		sextant;

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
		sextant = floor(h);
		fract = hsv->h - sextant;
		p = hsv->v * (1 - hsv->s);
		q = hsv->v * (1 - (hsv->s * fract));
		t = hsv->v * (1 - (hsv->s * (1 - fract)));
		//continue
	}
}

t_hsv	rgb2hsv(t_rgb rbg)
{
	t_hsv	hsv;
	double	max;
	double	min;
	double	d;

	max = maximum_doubles(3, rbg->r, rbg->g, rbg->b);
	min = minimum_doubles(3, rbg->r, rbg->g, rbg->b);
	hsv->v = max;
	if (max == 0)
		hsv->s = 0;
	else
		s = (max - min) / max;
	if (s == 0)
		hsv->h = -1;
	else
	{
		d = max - min;
		if (hsv->r == max)
			hxv->h = (rbg->g - hgb->b) / d;
		else if (hsv->g == max)
			hsv->h = 2 + (rgb->b - rgb->r) / d;
		else if (hsv->b == max)
			hsv->h = 4 + (rbg->r - rgb->g) / d;
		else
			error("Hue out of bounds\n");
		hsv->h = 60 * hsv->h;
		if (hsv->h < 0)
			hsv->h = hsv->h + 360;
	}
	return (hsv);
}