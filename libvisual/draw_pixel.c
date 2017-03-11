/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:46:19 by kdrumm            #+#    #+#             */
/*   Updated: 2017/02/21 22:46:20 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(t_map *map, int x, int y, int color)
{
	char	*address;

	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	address = &(map->address[((map->bits_per_pixel) * x / 8) + ((map->bytes_per_line) * y)]);
	ft_memcpy(address, &color, (map->bits_per_pixel) / 8);
}
