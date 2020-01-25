/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 22:16:29 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/29 20:38:18 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	norme_help(va_list ap, char **prec, char *flgs, int *i)
{
	int		start;

	(*i)++;
	if (flgs[(*i)] == '*')
	{
		free(*prec);
		if (!(*prec = ft_itoa(va_arg(ap, int))))
			return (0);
		(*i)++;
	}
	else if (ft_isdigit(flgs[(*i)]))
	{
		start = (*i);
		while (ft_isdigit(flgs[(*i)]))
			(*i)++;
		free(*prec);
		if (!(*prec = ft_substr(flgs, start, (*i) - start)))
			return (0);
	}
	return (1);
}

int			cut_prec(va_list ap, t_vrs *vrbs, int *i)
{
	char	*pr;

	if (!(pr = ft_strdup("0")))
		return (0);
	if (vrbs->flgs[(*i)] == '.')
	{
		if (!(norme_help(ap, &pr, vrbs->flgs, i)))
			return (0);
	}
	else if (vrbs->flgs[(*i)] != '.')
	{
		free(pr);
		if (!(pr = ft_strdup("-1")))
			return (0);
	}
	vrbs->prec = ft_atoi(pr);
	free(pr);
	return (1);
}
