/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:17:35 by kdrumm            #+#    #+#             */
/*   Updated: 2017/02/21 22:17:37 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Should make the error protection in this function look cleaner
*/

int		init_map(t_map **map, int w, int h, char *title)
{
	int		i;

	(*map) = (t_map *)malloc(sizeof(t_map));
	MALLOC_GUARD(*map);
	(*map)->dots = (t_pt ***)malloc(sizeof(t_pt **) * h);
	MALLOC_GUARD((*map)->dots);
	i = 0;
	while (i < h)
	{
		(*map)->dots[i] = (t_pt **)malloc(sizeof(t_pt *) * w);
		MALLOC_GUARD((*map)->dots[i]);
		i++;
	}
	(*map)->width = w;
	(*map)->height = h;
	(*map)->connection = mlx_init();
	(*map)->window = mlx_new_window((*map)->connection, (*map)->width, (*map)->height, title);
	(*map)->image = mlx_new_image((*map)->connection, (*map)->width, (*map)->height);
	(*map)->address = mlx_get_data_addr((*map)->image, &((*map)->bits_per_pixel),
		&((*map)->bytes_per_line), &((*map)->endian));
	if (!(*map)->address || !(*map)->image || !(*map)->window)
		return (0);
	return (1);
}
