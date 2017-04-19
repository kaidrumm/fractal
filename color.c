/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:59:36 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/18 22:26:40 by kaidrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_triple	*color(float i)
{
	t_triple	*rgb;

	if (!(rgb = (t_triple *)malloc(sizeof(*rgb))))
		ft_error("Malloc error in color\n");
	rgb->a = sinf(i);
	rgb->b = cosf(i);
	rgb->c = -cosf(i);
	rgb->a += 1;
	rgb->b += 1;
	rgb->c += 1;
	rgb->a *= 127;
	rgb->b *= 127;
	rgb->c *= 127;
	return (rgb);
}
