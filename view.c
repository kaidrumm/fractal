/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:52:42 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/03/27 15:57:02 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	translate(double delta_x, double delta_y)
// {

// }

// /*
// *
// void	zoom(double percent)
// {

// }
// /*/

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
	mlx_clear_window(map->connection, map->window);
	// do stuff to set image
	iteratePoints(map);
	mlx_put_image_to_window(map->connection, map->window, map->image, 0, 0);
	return (1);
}

/*
** Take the pixel measured from 0 to W/H and scale it to the map area from
** -2 to +2 by centering (subtracting half the scale) and multiplying by 4/scale
*/

double	scale2window(int scale, int pixel)
{
	//printf("Scale to window\n");
	return ((4 / (double)scale) * (double)(pixel - (scale / 2)));
}

// int		expose_hook(t_map *map)
// {
// 	//printf("Expose hook\n");
// 	mlx_clear_window(map->connection, map->window);
// 	mlx_put_image_to_window(map->connection, map->window, map->image, 0, 0);
// 	return (1);
// }

// void	complex_plane(t_map *map, t_pt *pt)
// {
// 	printf("Complex Plane\n");
// 	pt->real = (4 / (double)(map->width)) * (double)(pt->x - (map->width / 2));
// 	pt->imaginary = (4 / (double)(map->width)) * (double)(pt->y - (map->height / 2));
// }
