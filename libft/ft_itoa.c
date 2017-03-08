/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:34:45 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/27 20:11:30 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_mag(int n)
{
	int		mag;

	mag = 1;
	if (n < 0)
		mag++;
	while (ABS(n) >= 10)
	{
		n = n / 10;
		mag++;
	}
	return (mag);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		l;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = get_mag(n) + 1;
	s = (char *)malloc(sizeof(char) * l);
	MALLOC_GUARD(s);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[l - 1] = '\0';
	while (n > 0)
	{
		l--;
		s[l - 1] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}
