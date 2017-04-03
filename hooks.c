/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:52:42 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/04/02 20:50:15 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	map->fractal->c.r = x;
	map->fractal->c.i = y;
	expose_hook(map);
	return (button);
}

int		expose_hook(t_map *map)
{
	ft_bzero(map->address, map->bytes_per_line * map->height);
	iteratePoints(map);
	mlx_clear_window(map->connection, map->window);
	mlx_put_image_to_window(map->connection, map->window, map->image, 0, 0);
	return (1);
}
