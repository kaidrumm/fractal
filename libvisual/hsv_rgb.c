/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:03:35 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/24 12:16:56 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

/*
** Takes RGB values either in percentage form (between 0 and 1) or 0-255 values
** and translates them into a hexcode for that color (with no opacity).
*/

int			rgbtoi(t_triple *rgb)
{
	int		r;
	int		b;
	int		g;

	r = (int)round(rgb->a);
	g = (int)round(rgb->b);
	b = (int)round(rgb->c);
	if (rgb->a <= 1 && rgb->b <= 1 && rgb->c <= 1)
	{
		r = (int)round(rgb->a * 255);
		g = (int)round(rgb->b * 255);
		b = (int)round(rgb->c * 255);
	}
	return ((r * 0x10000) + (g * 0x100) + b);
}

int			check_rgb_fraction(t_triple *rgb)
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

static void	hsv_rgb_helper(t_triple *hsv, t_triple *rgb)
{
	int			sextant;
	t_triple	cmy;
	float		fract;

	if (hsv->a == 360)
		hsv->a = 0;
	else
		hsv->a = hsv->a / 60;
	sextant = floor(hsv->a);
	fract = hsv->a - sextant;
	update_triple(&cmy, hsv->c * (1 - hsv->b), hsv->c * (1 - (hsv->b *
		fract)),
		hsv->c * (1 - (hsv->b * (1 - fract))));
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
	else
		update_triple(rgb, hsv->c, cmy.a, cmy.b);
}

/*
** Expects S and V between 0 and 1, H as an angle in degrees
*/

t_triple	*hsv2rgb(t_triple *hsv)
{
	t_triple	*rgb;

	check_hsv(hsv);
	if (!(rgb = (t_triple *)malloc(sizeof(*rgb))))
		ft_error("Malloc error");
	if (hsv->b == 0 && hsv->a == -1)
		update_triple(rgb, hsv->c, hsv->c, hsv->c);
	else
		hsv_rgb_helper(hsv, rgb);
	return (rgb);
}
