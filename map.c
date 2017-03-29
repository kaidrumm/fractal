/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:17:35 by kdrumm            #+#    #+#             */
/*   Updated: 2017/03/28 20:07:57 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Can be used to apply any function to every pixel or dot on the map
*/

void	iteratePoints(t_map *map)
{
	int		i;
	int		j;

	//printf("Iterate Points\n");
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

void	init_fractal(t_map *map)
{
	if (!(map->fractal = (t_fractal *)malloc(sizeof(t_fractal))))
		ft_error("Malloc failure initializing fractal");
	map->fractal->maxIter = 500;
}

int		init_map(t_map **map, int w, int h, char *title)
{
	printf("Init map\n");
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
