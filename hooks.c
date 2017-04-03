/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:52:42 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/04/02 22:14:54 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_fractal *frac)
{
	// t_fractal	*frac;

	// frac = (t_fractal *)param;
	frac->c.r = x;
	frac->c.i = y;
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
	return (keycode);
}
