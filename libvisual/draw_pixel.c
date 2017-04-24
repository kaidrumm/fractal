/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:44:47 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/20 12:46:26 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

/*
** Skips drawing any pixel if it is out of range of the map area. Uses memcpy
** to enter the integer value of a color into the memory area of the image.
*/

void	draw_pixel(t_map *map, int x, int y, int color)
{
	char	*address;

	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	address = &(map->address[((map->bits_per_pixel) * x / 8) +
		((map->bytes_per_line) * y)]);
	ft_memcpy(address, &color, (map->bits_per_pixel) / 8);
}
