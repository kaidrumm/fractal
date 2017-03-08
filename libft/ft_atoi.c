/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 21:56:11 by kdrumm            #+#    #+#             */
/*   Updated: 2016/07/18 21:56:12 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_numbers(char *str, int i)
{
	int		nbr;

	nbr = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (10 * nbr) + (str[i] - '0');
		i++;
	}
	return (nbr);
}

static int		skip_whitespace(char *str, int i)
{
	while (str[i] != '\0')
	{
		if ((str[i] <= 32) && (str[i] >= 0))
			i++;
		else
			return (i);
	}
	return (i);
}

int				ft_atoi(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	i = skip_whitespace(str, i);
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		return (sign * read_numbers(str, i));
	}
	return (0);
}
