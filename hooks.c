/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:52:42 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/04/17 15:42:13 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractal *frac)
{
	printf("zoom in");
	frac->zoom *= 1.1;
	frac->x_offset = frac->x_offset / 1.1;
	frac->y_offset = frac->y_offset / 1.1;
	frac->width /= 1.1;
	frac->height /= 1.1;
	frac->maxIter += 5;
	// frac->x_offset = frac->x_offset * 1.1 + (frac->map->width * 1.1 - frac->map->width) / 2;
	// frac->y_offset = frac->y_offset * 1.1 + (frac->map->height * 1.1 - frac->map->height) / 2;
}

void	zoom_out(t_fractal *frac)
{
	printf("zoom out");
	frac->zoom /= 1.1;
	frac->x_offset = frac->x_offset * 1.1;
	frac->y_offset = frac->y_offset * 1.1;
	frac->width *= 1.1;
	frac->height *= 1.1;
	frac->maxIter -= 5;
	// frac->x_offset = frac->x_offset / 1.1 + (frac->map->width / 1.1 - frac->map->width) / 2;
	// frac->y_offset = frac->y_offset / 1.1 + (frac->map->height / 1.1 - frac->map->height) / 2;
}

int		mouse_hook(int button, int x, int y, t_fractal *frac)
{
	printf("button %i at %i, %i\n", button, x, y);
	if (button == 5 && frac->zoom < 50000)
		zoom_in(frac);
	else if (button == 4 && frac->zoom > 0)
		zoom_out(frac);
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
	printf("Keypress %i\n", keycode);
	if (keycode == 53)
		exit(0);
	else if ((keycode == 24 || keycode == 257) && frac->zoom < 50000)
		zoom_in(frac);
	else if ((keycode == 27 || keycode == 256) && frac->zoom > 0)
		zoom_out(frac);
	else if (keycode == 126) // up
		frac->y_offset -= 1 / frac->zoom / 5;
	else if (keycode == 124) // right
		frac->x_offset += 1 / frac->zoom / 5;
	else if (keycode == 125) // down
		frac->y_offset += 1 / frac->zoom / 5;
	else if (keycode == 123) // left
		frac->x_offset -= 1 / frac->zoom / 5;
	draw(frac);
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
