/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:46:19 by kdrumm            #+#    #+#             */
/*   Updated: 2017/03/23 21:10:29 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Skips drawing any pixel if it is out of range of the map area. Uses memcpy
** to enter the integer value of a color into the memory area of the image.
*/

void	draw_pixel(t_map *map, int x, int y, int color)
{
	char	*address;

	//printf("Draw pixel\n");
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	address = &(map->address[((map->bits_per_pixel) * x / 8) +
		((map->bytes_per_line) * y)]);
	ft_memcpy(address, &color, (map->bits_per_pixel) / 8);
}
