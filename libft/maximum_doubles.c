/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_doubles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:51:23 by KaiDrumm          #+#    #+#             */
/*   Updated: 2017/04/03 20:38:32 by KaiDrumm         ###   ########.us       */
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
