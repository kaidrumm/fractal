/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_floats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:12:29 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/03 20:36:48 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		minimum_doubles(int n, ...)
{
	va_list	numbers;
	double	minimum;
	double	temp;

	va_start(numbers, n);
	minimum = va_arg(numbers, double);
	while (n--)
	{
		temp = va_arg(numbers, double);
		if (temp < minimum)
			minimum = temp;
	}
	va_end(numbers);
	return (minimum);
}
