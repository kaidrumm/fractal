/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_doubles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:51:23 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/03/20 11:23:13 by kaidrumm         ###   ########.us       */
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
	printf("Maximum starts at... %f\n", maximum);
	while (--n)
	{
		printf("n is %i\n", n);
		temp = va_arg(numbers, double);
		printf("Temp is %f\n", temp);
		if (temp > maximum)
			maximum = temp;
	}
	va_end(numbers);
	return (maximum);
}
