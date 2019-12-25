/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundlers_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:35:11 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/25 22:46:01 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		cut_flg(char *flgs, int *i)
{
	char	flg;

	if (flgs[++(*i)] == '-')
		while (flgs[(*i)] == '-')
		{
			flg = '-';
			(*i)++;
		}
	else if (flgs[(*i)] == '0')
		while (flgs[(*i)] == '0')
		{
			flg = '0';
			(*i)++;
		}
	else
		flg = '\0';
	return (flg);
}

char		*neg_nbr(char *str)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '-')
		{
			pos = i;
			break ;
		}
	if (pos == 0 || !ft_isdigit(str[pos - 1]))
		return (str);
	str[pos] = '0';
	str[0] = '-';
	return (str);
}

static	int	norme_help(char *val, int prec, char **str_c, int *i)
{
	char *str;

	if (ft_atoi(val) > 0)
	{
		if (!(str = malloc(prec + 1)))
			return (0);
		str[prec] = '\0';
		*i = prec;
	}
	else
	{
		if (!(str = malloc(prec + 2)))
			return (0);
		str[prec + 1] = '\0';
		*i = prec + 1;
	}
	*str_c = str;
	return (1);
}

char		*get_s_p(char *val, int prec)
{
	char	*str_c;
	int		i;
	int		j;

	str_c = NULL;
	if (!(norme_help(val, prec, &str_c, &i)))
		return (NULL);
	while (--i >= 0)
		str_c[i] = '0';
	i = (ft_atoi(val) > 0) ? prec : prec + 1;
	j = ft_strlen(val);
	while (--j >= 0)
		str_c[--i] = val[j];
	if (ft_atoi(val) < 0)
		str_c = neg_nbr(str_c);
	return (str_c);
}

char		*get_s_p_u(char *val, int prec)
{
	char	*str_c;
	int		i;
	int		j;

	str_c = NULL;
	if (!(str_c = malloc(prec + 1)))
		return (NULL);
	str_c[prec] = '\0';
	i = prec;
	while (--i >= 0)
		str_c[i] = '0';
	i = prec;
	j = ft_strlen(val);
	while (--j >= 0)
		str_c[--i] = val[j];
	return (str_c);
}
