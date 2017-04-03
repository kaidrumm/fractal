/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:17:35 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/02 20:59:13 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This can be used to apply any function to every pixel or dot on the map.
*/

void	iteratePoints(t_map *map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			fractal(map, i, j);
			i++;
		}
		j++;
	}
}

/*
** Might be generalized to the library to all graphic projects
*/

int		init_map(t_map **map, int w, int h, char *title)
{
	if (!((*map) = (t_map *)malloc(sizeof(t_map))))
		ft_error("Malloc error in init_map");
	(*map)->width = w;
	(*map)->height = h;
	(*map)->connection = mlx_init();
	(*map)->window = mlx_new_window((*map)->connection, (*map)->width, (*map)->height, title);
	(*map)->image = mlx_new_image((*map)->connection, (*map)->width, (*map)->height);
	(*map)->address = mlx_get_data_addr((*map)->image, &((*map)->bits_per_pixel),
		&((*map)->bytes_per_line), &((*map)->endian));
	if (!(*map)->address || !(*map)->image || !(*map)->window)
		ft_error("Invalid map pointers in init_map");
	return (1);
}
