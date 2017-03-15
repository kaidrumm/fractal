/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_doubles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:12:29 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/03/14 15:27:23 by kaidrumm         ###   ########.us       */
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
