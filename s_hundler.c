/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:43:14 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/25 15:16:03 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prec_cnt_str(t_list *tmp, vr_list *vrbs)
{
	int i;
	int j;

	i = vrbs->width;
	while (--i >= 0)
		tmp->str[i] = ' ';
	if (!(vrbs->str_c = get_s_p_s(vrbs->val, vrbs->prec)))
		return (0);
	if (vrbs->flg == '-')
	{
		i = -1;
		while (++i < (int)ft_strlen(vrbs->str_c))
			tmp->str[i] = vrbs->str_c[i];
	}
	else
	{
		i = vrbs->width;
		j = ft_strlen(vrbs->str_c);
		while (--j >= 0)
			tmp->str[--i] = vrbs->str_c[j];
	}
	return (1);
}

static	int	norme_help(t_list *tmp, vr_list *vrbs)
{
	if (!(tmp->str = ft_strdup(vrbs->val)))
		return (0);
	if (vrbs->width != -1)
		if (!(ft_width_str(tmp, vrbs)))
			return (0);
	if (vrbs->prec >= 0 && vrbs->prec > vrbs->width &&
	vrbs->width < (int)ft_strlen(vrbs->val))
	{
		if (!(vrbs->str_c = get_s_p_s(vrbs->val, vrbs->prec)))
			return (0);
		free(tmp->str);
		if (!(tmp->str = ft_strdup(vrbs->str_c)))
			return (0);
	}
	else if (vrbs->prec >= 0)
		if (!(ft_prec_cnt_str(tmp, vrbs)))
			return (0);
	free_vrbs(vrbs);
	return (1);
}

int			str_spf_s(va_list ap, t_list *tmp)
{
	vr_list	*vrbs;
	int		i;

	i = -1;
	if (!(vrbs = l_lstnew_vrbs()))
		return (0);
	vrbs->flgs = tmp->flg;
	if (vrbs->flgs[0] == '\0')
	{
		if (!(tmp->str = ft_strdup(va_arg(ap, char*))))
			tmp->str = ft_strdup("(null)");
		free_vrbs(vrbs);
		return (1);
	}
	vrbs->flg = cut_flg(vrbs->flgs, &i);
	if ((vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg)) == -2)
		return (0);
	if ((vrbs->prec = cut_prec(ap, vrbs->flgs, &i)) == -2)
		return (0);
	if (!(vrbs->val = ft_strdup(va_arg(ap, char*))))
		vrbs->val = ft_strdup("(null)");
	if (!(norme_help(tmp, vrbs)))
		return (0);
	return (1);
}
