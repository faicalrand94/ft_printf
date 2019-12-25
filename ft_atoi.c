/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 00:54:54 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/25 18:37:59 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		helper(const char *str, int *sign)
{
	int		i;

	i = 0;
	*sign = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\r'))
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = helper(str, &sign);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + str[i++] - 48;
			if ((res * sign) > 2147483647)
				return (-1);
			else if ((res * sign) < (-2147483648))
				return (0);
		}
		else
			break ;
	return ((int)(res * sign));
}
