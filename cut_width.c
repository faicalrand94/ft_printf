/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 20:41:52 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/29 20:38:07 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		norme_help(int val, char **width, t_vrs *vrbs)
{
	if (val >= 0)
	{
		if (!(*width = ft_itoa(val)))
			return (0);
	}
	else
	{
		if (!(*width = ft_itoa(-1 * val)))
			return (0);
		vrbs->flg = '-';
	}
	return (1);
}

int				cut_width(va_list ap, t_vrs *vrbs, int *i)
{
	int		start;
	char	*width;

	start = *i;
	if (vrbs->flgs[(*i)] == '*')
	{
		vrbs->width = va_arg(ap, int);
		if (!(norme_help(vrbs->width, &width, vrbs)))
			return (0);
		(*i)++;
	}
	else if (ft_isdigit(vrbs->flgs[(*i)]))
	{
		while (ft_isdigit(vrbs->flgs[(*i)]))
			(*i)++;
		if (!(width = ft_substr(vrbs->flgs, start, (*i) - start)))
			return (0);
	}
	else if (!(width = ft_strdup("-1")))
		return (0);
	vrbs->width = ft_atoi(width);
	free(width);
	return (1);
}
