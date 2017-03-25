/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbtoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:22:04 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/03/23 20:54:16 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Takes RGB values either in percentage form (between 0 and 1) or 0-255 values
** and translates them into a hexcode for that color (with no opacity).
*/

int		rgbtoi(t_triple *rgb)
{
	int		r;
	int		b;
	int		g;

	//printf("RGB to I\n");
	r = (int)round(rgb->a);
	g = (int)round(rgb->b);
	b = (int)round(rgb->c);
	if (rgb->a <= 1 && rgb->b <= 1 && rgb->c <= 1)
	{
		r = (int)round(rgb->a * 255);
		g = (int)round(rgb->b * 255);
		b = (int)round(rgb->c * 255);
	}
	//printf("Int color is %x\n", (r * 0x10000) + (g * 0x100) + b);
	return ((r * 0x10000) + (g * 0x100) + b);
}