/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:41 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/24 16:22:55 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prec_cnt(t_list *tmp, vr_list *vrbs)
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

static int	ft_prec_cnt2(t_list *tmp, vr_list *vrbs)
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
		return (0);
    tmp->str[i] = '\0';
    j = -1;
    while (++j < i)
      tmp->str[j] = '0';
      j = ft_strlen(vrbs->val);
    while (--j >= 0)
    {
      tmp->str[--i] = vrbs->val[j];
    }
	return (1);
}

static int		ft_prec(vr_list *vrbs, t_list *tmp)
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
		if ((int)ft_strlen(vrbs->val) > vrbs->prec)
			ft_prec_cnt2(tmp, vrbs);
		else if (vrbs->flg == '-' && vrbs->width > vrbs->prec)
			ft_prec_cnt(tmp, vrbs);
		else if (vrbs->width > vrbs->prec)
			ft_prec_cnt(tmp, vrbs);
		else if (vrbs->width <= vrbs->prec)
			ft_prec_cnt2(tmp, vrbs);
	}
	if (vrbs->val[0] == '0' && vrbs->prec == 0 &&
		   	(vrbs->width == 0 || vrbs->width == -1))
	{
		free(tmp->str);
		tmp->str = ft_strdup("");
	}
	return (1);
}

int str_spf_u(va_list ap, t_list *tmp)
{
  vr_list *vrbs;
  int i;

  i = -1;
  if (!(vrbs = l_lstnew_vrbs()))
	return (0);
  vrbs->flgs = tmp->flg;
  if (vrbs->flgs[0] == '\0')
  {
    if (!(tmp->str = ft_itoa((unsigned int)va_arg(ap, unsigned int))))
		return (0);
	free_vrbs(vrbs);
    return (1);
  }
  vrbs->flg = cut_flg(vrbs->flgs, &i);
  if ((vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg)) == -2)
		return (0);
	if ((vrbs->prec = cut_prec(ap, vrbs->flgs, &i)) == -2)
		return (0);
  	vrbs->u_val = va_arg(ap, unsigned int);
  	if (!(vrbs->val = ft_itoa(vrbs->u_val)))
		return (0);
  	if (!(tmp->str = ft_strdup(vrbs->val)))
		return (0);
	if (vrbs->width != -1)
		if (!(ft_width(tmp, vrbs)))
			return (0);
	if (vrbs->prec != -1)
		if (!ft_prec(vrbs, tmp))
			return (0);
	free_vrbs(vrbs);
	return (1);
}
