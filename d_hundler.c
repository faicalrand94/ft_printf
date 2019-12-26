/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:30:53 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:50:04 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	norme_help(t_list *tmp, t_vrs *vrbs)
{
	if (!(vrbs->val = ft_itoa(vrbs->val_i)))
		return (0);
	if (!(tmp->str = ft_strdup(vrbs->val)))
		return (0);
	if (vrbs->width != -1)
		if (!(ft_width(tmp, vrbs)))
			return (0);
	if (vrbs->prec != -1)
		if (!(ft_prec_d(vrbs, tmp)))
			return (0);
	free_vrbs(vrbs);
	return (1);
}

int			str_spf_d(va_list ap, t_list *tmp)
{
	t_vrs	*vrbs;
	int		i;

	i = -1;
	if (!(vrbs = l_lstnew_vrbs()))
		return (0);
	vrbs->flgs = tmp->flg;
	if (vrbs->flgs[0] == '\0')
	{
		if (!(tmp->str = ft_itoa(va_arg(ap, int))))
			return (0);
		free_vrbs(vrbs);
		return (1);
	}
	vrbs->flg = cut_flg(vrbs->flgs, &i);
	if ((vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg)) == -2)
		return (0);
	if ((vrbs->prec = cut_prec(ap, vrbs->flgs, &i)) == -2)
		return (0);
	vrbs->val_i = va_arg(ap, int);
	if (!(norme_help(tmp, vrbs)))
		return (0);
	return (1);
}
