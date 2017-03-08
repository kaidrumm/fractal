/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 23:35:14 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/27 20:12:10 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_mag(int n, int b)
{
	int		mag;

	mag = 1;
	if (n < 0)
		mag++;
	while (ABS(n) >= b)
	{
		n = n / b;
		mag++;
	}
	return (mag);
}

char		*ft_itoa_base(int n, int base)
{
	char	*s;
	int		l;
	char	*basestring;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = get_mag(n, base) + 1;
	s = (char *)malloc(sizeof(char) * l);
	MALLOC_GUARD(s);
	basestring = "0123456789abcdef";
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
		s[l - 1] = basestring[n % base];
		n = n / base;
	}
	return (s);
}
