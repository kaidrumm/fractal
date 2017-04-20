/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:44:47 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/20 12:46:24 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractal *frac, float x, float y)
{
	frac->zoom *= 1.1;
	frac->width /= 1.1;
	frac->height /= 1.1;
	frac->x_offset = x - frac->width / 2;
	frac->y_offset = y - frac->height / 2;
	frac->maxIter += 5;
}

void	zoom_out(t_fractal *frac, float x, float y)
{
	frac->zoom /= 1.1;
	frac->width *= 1.1;
	frac->height *= 1.1;
	frac->x_offset = x - frac->width / 2;
	frac->y_offset = y - frac->height / 2;
	frac->maxIter -= 5;
}

int		mouse_hook(int button, int x, int y, t_fractal *frac)
{
	float	x_coord;
	float	y_coord;

	printf("Button %i\n", button);
	x_coord = ((float)x * frac->width / frac->map->width) + frac->x_offset;
	y_coord = ((float)y * frac->height / frac->map->height) + frac->y_offset;
	if (button == 1)
		zoom_in(frac, x_coord, y_coord);
	if (button == 5 && frac->zoom < 50000)
		zoom_in(frac, x_coord, y_coord);
	else if (button == 4 && frac->zoom > 0)
		zoom_out(frac, x_coord, y_coord);
	expose_hook(frac);
	return (button);
}

int		expose_hook(t_fractal *frac)
{
	ft_bzero(frac->map->address, frac->map->bytes_per_line * frac->map->height);
	mlx_clear_window(frac->map->connection, frac->map->window);
	iteratePoints(frac->map, &scale2view, frac);
	mlx_put_image_to_window(frac->map->connection, frac->map->window,
		frac->map->image, 0, 0);
	return (1);
}

int		key_hook(int keycode, t_fractal *frac)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 49)
		init_fractal(frac, frac->type);
	else if ((keycode == 24 || keycode == 257) && frac->zoom < 50000)
		zoom_in(frac, frac->x_offset + frac->width / 2, frac->y_offset + frac->height / 2);
	else if ((keycode == 27 || keycode == 256) && frac->zoom > 0)
		zoom_out(frac, frac->x_offset + frac->width / 2, frac->y_offset + frac->height / 2);
	else if (keycode == 126)
		frac->y_offset -= 1 / frac->zoom / 5;
	else if (keycode == 124)
		frac->x_offset += 1 / frac->zoom / 5;
	else if (keycode == 125)
		frac->y_offset += 1 / frac->zoom / 5;
	else if (keycode == 123)
		frac->x_offset -= 1 / frac->zoom / 5;
	else if (keycode == 8)
		frac->color_mode = (frac->color_mode + 1) % 2;
	else if (keycode == 7)
		frac->color_offset -= 1;
	else if (keycode == 9)
		frac->color_offset += 1;
	else if (keycode == 259)
		frac->freeze = (frac->freeze + 1) % 2;
	expose_hook(frac);
	return (keycode);
}

/*
** Alters the julia set C coordinates continuously when the mouse drags
** across the window.
*/

int		mouse_move(int x, int y, t_fractal *frac)
{
	if (frac->freeze == 0)
	{
		frac->c.r = ((float)x * 2 / frac->map->width) - 1;
		frac->c.i = ((float)y * 2 / frac->map->height) - 1;
		expose_hook(frac);
	}
	return (1);
}
