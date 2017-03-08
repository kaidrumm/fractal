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

int		init_map(t_map **map, int w, int h, char *title)
{
	(*map) = (t_map *)malloc(sizeof(t_map));
	MALLOC_GUARD(*map);
	(*map)->dots = (t_pt ***)malloc(sizeof(t_pt **) * 2000);
	MALLOC_GUARD((*map)->dots);
	(*map)->max_x = 0;
	(*map)->max_z = 0;
	(*map)->w = w;
	(*map)->h = h;
	(*map)->cnx = mlx_init();
	(*map)->win = mlx_new_window((*map)->cnx, (*map)->w, (*map)->h, title);
	(*map)->image_option = 1;
	(*map)->projection_option = 1;
	(*map)->img = mlx_new_image((*map)->cnx, (*map)->w, (*map)->h);
	(*map)->addr = mlx_get_data_addr((*map)->img, &((*map)->bpp),
		&((*map)->bpl), &((*map)->endian));
	if (!(*map)->addr || !(*map)->img || !(*map)->win)
		return (0);
	return (1);
}
