/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:49:57 by kdrumm            #+#    #+#             */
/*   Updated: 2017/01/27 16:49:58 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**
*/

int		ColorHSV(int a, int b, int c)
{

}

/*
**
*/

int		HSVtoRGB()
{

}

int		main(void)
{
	t_map	**map;
	double	c_real;
	double	c_imaginary;
	double	new_real;
	double	new_imaginary;
	double	old_real;
	double	old_imaginary;
	double	zoom = 1;
	double	moveX = 0;
	double	moveY = 0;
	int		color;
	int		maxIterations = 300;
	int		x;
	int		y;
	int		i;

	init_map(map, 1300, 1000, "Julia Set");
	c_real = -0.7;
	c_imaginary = 0.27015;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			new_real = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
			new_imaginary = (y - h / 2) / (0.5 * zoom * h) + moveY;
			i = 0;
			while (i < maxIterations)
			{
				old_real = new_real;
				old_imaginary = new_imaginary;
				new_real = old_real * old_real - old_imaginary * old_imaginary + c_real;
				new_imaginary = 2 * old_real * old_imaginary + c_imaginary;
				if ((new_real * new_real + new_imaginary * new_imaginary) > 4)
					break;
				i++;
			}
			color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations))); // this function has to be built
			draw_pixel(map, x, y, color);
			x++;
		}
		y++;
	}
	expose();
	return (0);
}