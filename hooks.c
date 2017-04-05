/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:52:42 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/04/05 12:13:02 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_fractal *frac)
{
	printf("button %i at %i, %i\n", button, x, y);
	if (button == 4)
	{
		printf("zoom out");
		//scroll down (zoom out)
	}
	else if (button == 5)
	{
		printf("zoom in");
		//scroll up (zoom in)
	}
	draw(frac);
	return (button);
}

int		expose_hook(t_fractal *frac)
{
	ft_bzero(frac->map->address, frac->map->bytes_per_line * frac->map->height);
	mlx_clear_window(frac->map->connection, frac->map->window);
	iteratePoints(frac->map, &scale2view, frac);
	mlx_put_image_to_window(frac->map->connection, frac->map->window, frac->map->image, 0, 0);
	return (1);
}

int		key_hook(int keycode, t_fractal *frac)
{
	printf("Keypress %i", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		zoom(frac, 101);
	return (keycode);
}

/*
** Alters the julia set C coordinates continuously when the mouse drags across the window.
*/

int		mouse_move(int x, int y, t_fractal *frac)
{
	frac->c.r = ((float)x * 2 / frac->map->width) - 1;
	frac->c.i = ((float)y * 2 / frac->map->height) - 1;
	draw(frac);
	return (1);
}
