/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:30:15 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/01 15:30:17 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_size(long c)
{
	int	cpt;

	cpt = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		cpt++;
		c = c * (-1);
	}
	while (c > 0)
		if (c < 10)
		{
			cpt++;
			break ;
		}
		else if (c >= 10)
		{
			cpt++;
			c = c / 10;
		}
	return (cpt);
}

static	void	ft_rstr(char *str, long l, int cpt)
{
	if (l < 0)
	{
		l = l * (-1);
		str[0] = '-';
	}
	while (l > 0)
		if (l < 10)
		{
			str[cpt--] = l + '0';
			break ;
		}
		else
		{
			str[cpt--] = (l % 10) + '0';
			l = l / 10;
		}
}

char			*ft_itoa(int n)
{
	long	l;
	char	*str;
	int		cpt;

	l = n;
	cpt = ft_size(l);
	if (!(str = malloc(sizeof(char) * cpt + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[cpt] = '\0';
	cpt--;
	ft_rstr(str, l, cpt);
	return (str);
}
