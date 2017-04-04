/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:52:42 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/04/03 20:28:19 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_fractal *frac)
{
	if (frac->type != 2 && frac->type != 4)
		return (0);
	frac->c.r = ((float)x * 2 / frac->map->width) - 1;
	frac->c.i = ((float)y * 2 / frac->map->height) - 1;
	expose_hook(frac);
	return (button);
}

int		expose_hook(t_fractal *frac)
{
	ft_bzero(frac->map->address, frac->map->bytes_per_line * frac->map->height);
	iteratePoints(frac->map, &fractal, frac);
	mlx_clear_window(frac->map->connection, frac->map->window);
	mlx_put_image_to_window(frac->map->connection, frac->map->window, frac->map->image, 0, 0);
	return (1);
}

int		key_hook(int keycode, t_fractal *frac)
{
	printf("Pointer %p", frac);
	if (keycode == 53)
		exit(0);
	return (keycode);
}

/*
** Alters the julia set C coordinates continuously when the mouse drags across the window.
*/

int		mouse_move(int x, int y, t_fractal *frac)
{
	frac->c.r = ((float)x * 2 / frac->map->width) - 1;
	frac->c.i = ((float)y * 2 / frac->map->height) - 1;
	expose_hook(frac);
	return (1);
}