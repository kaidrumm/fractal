/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:33:22 by kdrumm            #+#    #+#             */
/*   Updated: 2016/10/10 22:33:23 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_digit(char c, int b)
{
	char	*lower;
	char	*upper;
	int		i;

	if (c >= '0' && c <= '9')
		return (c - 48);
	else
	{
		i = 0;
		lower = "abcdef";
		upper = "ABCDEF";
		while (lower[i] && i < b - 10)
		{
			if (lower[i] == c || upper[i] == c)
				return (i + 10);
			i++;
		}
	}
	return (-1);
}

int			ft_atoi_base(char *str, int base)
{
	int		nbr;
	int		i;
	int		sign;
	int		d;

	nbr = 0;
	i = 0;
	d = 0;
	sign = 1;
	str = ft_strtrim(str);
	while (str[i])
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		d = convert_digit(str[i], base);
		if (d >= 0 && ++i)
			nbr = (base * nbr) + d;
	}
	return (nbr);
}
