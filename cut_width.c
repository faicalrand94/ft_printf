/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 20:41:52 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/25 22:48:18 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		norme_help(int val, char **width, char *flg)
{
	if (val >= 0)
	{
		if (!(*width = ft_itoa(val)))
			return (-2);
	}
	else
	{
		if (!(*width = ft_itoa(-1 * val)))
			return (-2);
		*flg = '-';
	}
	return (1);
}

int		cut_width(va_list ap, char *flgs, int *i, char *flg)
{
	int		start;
	char	*width;
	int		val;

	start = *i;
	if (flgs[(*i)] == '*')
	{
		val = va_arg(ap, int);
		if (!(norme_help(val, &width, flg)))
			return (-2);
		(*i)++;
	}
	else if (ft_isdigit(flgs[(*i)]))
	{
		while (ft_isdigit(flgs[(*i)]))
			(*i)++;
		if (!(width = ft_substr(flgs, start, (*i) - start)))
			return (-2);
	}
	else if (!(width = ft_strdup("-1")))
		return (-2);
	val = ft_atoi(width);
	free(width);
	return (val);
}
