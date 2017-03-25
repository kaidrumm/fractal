/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:52:42 by kaidrumm          #+#    #+#             */
/*   Updated: 2017/03/23 21:07:57 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Take the pixel measured from 0 to W/H and scale it to the map area from
** -2 to +2 by centering (subtracting half the scale) and multiplying by 4/scale
*/

double	scale2window(int scale, int pixel)
{
	//printf("Scale to window\n");
	return ((4 / (double)scale) * (double)(pixel - (scale / 2)));
}

int		expose_hook(t_map *map)
{
	//printf("Expose hook\n");
	mlx_clear_window(map->connection, map->window);
	mlx_put_image_to_window(map->connection, map->window, map->image, 0, 0);
	return (1);
}

// void	complex_plane(t_map *map, t_pt *pt)
// {
// 	printf("Complex Plane\n");
// 	pt->real = (4 / (double)(map->width)) * (double)(pt->x - (map->width / 2));
// 	pt->imaginary = (4 / (double)(map->width)) * (double)(pt->y - (map->height / 2));
// }
