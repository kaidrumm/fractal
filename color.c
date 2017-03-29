/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:59:36 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/03/28 20:04:18 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_triple	*color(int i)
{
	t_triple	*rgb;

	if (!(rgb = (t_triple *)malloc(sizeof(*rgb))))
		ft_error("Malloc error in color\n");
	rgb->a = (sin(i) + 1) * 127;
	rgb->b = (cos(i) + 1) * 127;
	rgb->c = (-cos(i) + 1) * 127;
	return (rgb);
}