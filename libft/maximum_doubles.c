/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_doubles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:51:23 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/24 12:18:26 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		maximum_doubles(int n, ...)
{
	va_list	numbers;
	double	maximum;
	double	temp;

	va_start(numbers, n);
	maximum = va_arg(numbers, double);
	while (--n)
	{
		temp = va_arg(numbers, double);
		if (temp > maximum)
			maximum = temp;
	}
	va_end(numbers);
	return (maximum);
}
