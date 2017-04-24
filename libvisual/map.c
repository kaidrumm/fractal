/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:44:47 by kdrumm            #+#    #+#             */
/*   Updated: 2017/04/24 12:13:30 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

/*
** This can be used to apply any function to every pixel or dot on the map.
*/

void	iterate_points(t_map *map, int (*f)(void	*p, int i, int j), void *p)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			f(p, i, j);
			i++;
		}
		j++;
	}
}

/*
** Might be generalized to the library to all graphic projects
*/

t_map	*init_map(int w, int h, char *title)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		ft_error("Malloc error in init_map");
	map->width = w;
	map->height = h;
	map->connection = mlx_init();
	map->window = mlx_new_window(map->connection, map->width, map->height,
		title);
	map->image = mlx_new_image(map->connection, map->width, map->height);
	map->address = mlx_get_data_addr(map->image, &(map->bits_per_pixel),
		&(map->bytes_per_line), &(map->endian));
	if (!map->address || !map->image || !map->window)
		ft_error("Invalid map pointers in init_map");
	return (map);
}
