/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_doubles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kelly <kdrumm@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:12:29 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/03/13 22:15:47 by KaiDrumm         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		minimum_doubles(int n, ...)
{
	va_list	numbers;
	double	minimum;
	double	temp;

	va_start(numbers, n)
	maximum = va_arg(numbers, double);
	while (n--)
	{
		temp = va_arg(numbers, double)
		if (temp < maximum)
			maximum = temp;
	}
	va_end(numbers);
	return (minimum);
}
