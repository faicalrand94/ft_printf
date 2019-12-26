/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:35:05 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:51:34 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_prec_cnt(t_list *tmp, t_vrs *vrbs)
{
	int i;
	int j;

	i = vrbs->width;
	while (--i >= 0)
		tmp->str[i] = ' ';
	if (!(vrbs->str_c = get_s_p_u(vrbs->val, vrbs->prec)))
		return (0);
	j = vrbs->prec;
	if (vrbs->flg == '-')
	{
		i = -1;
		while (++i < j)
			tmp->str[i] = vrbs->str_c[i];
	}
	else
	{
		i = vrbs->width;
		while (--j >= 0)
			tmp->str[--i] = vrbs->str_c[j];
	}
	return (1);
}

static	int	ft_prec_cnt2(t_list *tmp, t_vrs *vrbs)
{
	int i;
	int j;

	if ((int)ft_strlen(vrbs->val) > vrbs->prec)
	{
		i = -1;
		while (tmp->str[++i] == '0' || tmp->str[i] == '-')
			tmp->str[i] = ' ';
		if (vrbs->val_i < 0)
			tmp->str[--i] = '-';
		return (1);
	}
	if (!(vrbs->str_c = ft_strdup(tmp->str)))
		return (0);
	free(tmp->str);
	i = vrbs->prec;
	if (!(tmp->str = malloc(i + 1)))
		tmp->str[i] = '\0';
	j = -1;
	while (++j < i)
		tmp->str[j] = '0';
	j = ft_strlen(vrbs->val);
	while (--j >= 0)
		tmp->str[--i] = vrbs->val[j];
	return (1);
}

static	int	norme_prec_x(t_vrs *vrbs, t_list *tmp)
{
	if ((int)ft_strlen(vrbs->val) > vrbs->prec)
	{
		if (!(ft_prec_cnt2(tmp, vrbs)))
			return (0);
	}
	else if (vrbs->flg == '-' && vrbs->width > vrbs->prec)
	{
		if (!(ft_prec_cnt(tmp, vrbs)))
			return (0);
	}
	else if (vrbs->width > vrbs->prec)
	{
		if (!(ft_prec_cnt(tmp, vrbs)))
			return (0);
	}
	else if (vrbs->width <= vrbs->prec)
	{
		if (!(ft_prec_cnt2(tmp, vrbs)))
			return (0);
	}
	return (1);
}

int			ft_prec_x(t_vrs *vrbs, t_list *tmp)
{
	int i;

	if (vrbs->u_val == 0 && vrbs->prec == 0)
	{
		i = vrbs->width;
		while (--i >= 0)
			tmp->str[i] = ' ';
	}
	else if (vrbs->prec >= 0)
	{
		if (!(norme_prec_x(vrbs, tmp)))
			return (0);
	}
	if (vrbs->val[0] == '0' && vrbs->prec == 0 &&
			(vrbs->width == 0 || vrbs->width == -1))
	{
		free(tmp->str);
		if (!(tmp->str = ft_strdup("")))
			return (0);
	}
	return (1);
}
