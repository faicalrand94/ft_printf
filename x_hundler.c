/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:54:39 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/13 17:54:47 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prec_cnt(t_list *tmp, vr_list *vrbs)
{
	int i;
	int j;

	i = vrbs->width;
	while (--i >= 0)
		tmp->str[i] = ' ';
	vrbs->str_c = get_s_p_u(vrbs->val, vrbs->prec);
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
}

static void	ft_prec_cnt2(t_list *tmp, vr_list *vrbs)
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
		return ;
	}
	vrbs->str_c = ft_strdup(tmp->str);
    free(tmp->str);
    i = vrbs->prec;
    tmp->str = malloc(i + 1);
    tmp->str[i] = '\0';
    j = -1;
    while (++j < i)
      tmp->str[j] = '0';
      j = ft_strlen(vrbs->val);
    while (--j >= 0)
    {
      tmp->str[--i] = vrbs->val[j];
    }
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

int str_spf_x(va_list ap, t_list *tmp)
{
  vr_list *vrbs;
  int i;

  i = -1;
  vrbs = l_lstnew_vrbs();
  vrbs->flgs = tmp->flg;
  if (vrbs->flgs[0] == '\0')
  {
    tmp->str = ft_itoa((unsigned int)va_arg(ap, unsigned int));
    return (1);
  }
  vrbs->flg = cut_flg(vrbs->flgs, &i);
  vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg);
  vrbs->prec = cut_prec(ap, vrbs->flgs, &i);
  vrbs->u_val = va_arg(ap, unsigned int);
  vrbs->val = ft_itoa_int16(vrbs->u_val);
  tmp->str = ft_strdup(vrbs->val);
  if (vrbs->width != -1)
    ft_width(tmp, vrbs);
  if (vrbs->prec != -1)
		if (ft_prec(vrbs, tmp) == -1)
			return (-1);
  return (1);
}
