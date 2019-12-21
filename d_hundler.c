/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:30:53 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/20 22:59:13 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prec_cnt(t_list *tmp, vr_list *vrbs)
{
	int i;
	int j;

	i = vrbs->width;
	while (--i >= 0)
		tmp->str[i] = ' ';
	if (!(vrbs->str_c = get_s_p(vrbs->val, vrbs->prec)))
		return (0);
	j = (vrbs->val_i >= 0) ? vrbs->prec : vrbs->prec + 1;
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

int		ft_prec_cnt2(t_list *tmp, vr_list *vrbs)
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
	i = (vrbs->val_i > 0) ? vrbs->prec : vrbs->prec + 1;
	if (!(tmp->str = malloc(i + 1)))
		return (0);
	tmp->str[i] = '\0';
	j = -1;
	while (++j < i)
		tmp->str[j] = '0';
	j = ft_strlen(vrbs->val);
	while (--j >= 0)
		tmp->str[--i] = vrbs->val[j];
	if (vrbs->val_i < 0)
		if (!(tmp->str = neg_nbr(tmp->str)))
			return (0);
	return (1);
}

int		ft_prec(vr_list *vrbs, t_list *tmp)
{
	int i;

	if (vrbs->val[0] == '0' && vrbs->prec == 0)
	{
		i = vrbs->width;
		while (--i >= 0)
			tmp->str[i] = ' ';
	}
	else if (vrbs->prec >= 0)
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

int		str_spf_d(va_list ap, t_list *tmp)
{
	vr_list	*vrbs;
	int		i;

	i = -1;
	vrbs = l_lstnew_vrbs();
	vrbs->flgs = tmp->flg;
	if (vrbs->flgs[0] == '\0')
	{
		if (!(tmp->str = ft_itoa(va_arg(ap, int))))
			return (0);
		return (1);
	}
	vrbs->flg = cut_flg(vrbs->flgs, &i);
	if ((vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg)) == -2)
		return (0);
	if ((vrbs->prec = cut_prec(ap, vrbs->flgs, &i)) == -2)
		return (0);
	vrbs->val_i = va_arg(ap, int);
	if (!(vrbs->val = ft_itoa(vrbs->val_i)))
		return (0);
	if (!(tmp->str = ft_strdup(vrbs->val)))
		return (0);
	if (vrbs->width != -1)
		if (!(ft_width(tmp, vrbs)))
			return (0);
	if (vrbs->prec != -1)
		if (!(ft_prec(vrbs, tmp)))
			return (0);
	return (1);
}
