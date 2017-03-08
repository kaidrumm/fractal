/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 22:46:19 by kdrumm            #+#    #+#             */
/*   Updated: 2017/02/21 22:46:20 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	draw_pixel(t_map *map, int x, int y, int color)
{
	char	*addr;

	if (x < 0 || y < 0 || x >= map->w || y >= map->h)
		return ;
	if (map->image_option == 1)
	{
		addr = &(map->addr[((map->bpp) * x / 8) + ((map->bpl) * y)]);
		ft_memcpy(addr, &color, (map->bpp) / 8);
	}
	else
		mlx_pixel_put(map->cnx, map->win, x, y, 0Xd56497);
}
