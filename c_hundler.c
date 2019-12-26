/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:55:18 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:49:50 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	norme_help(t_list *tmp, t_vrs *vrbs)
{
	if (vrbs->flgs[0] == '\0')
	{
		tmp->str = vrbs->val;
		return (1);
	}
	if (!(tmp->str = ft_strdup(vrbs->val)))
		return (0);
	if (vrbs->width != -1)
		if (!(ft_width_str(tmp, vrbs)))
			return (0);
	free_vrbs(vrbs);
	return (1);
}

int			str_spf_c(va_list ap, t_list *tmp)
{
	t_vrs	*vrbs;
	int		i;

	i = -1;
	if (!(vrbs = l_lstnew_vrbs()))
		return (0);
	vrbs->flgs = tmp->flg;
	vrbs->flg = cut_flg(vrbs->flgs, &i);
	if ((vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg)) == -2)
		return (0);
	if (!(vrbs->val = (char*)malloc(sizeof(char) * 2)))
		return (0);
	if ((vrbs->val_i = va_arg(ap, int)) == 0 && vrbs->flg == '-')
		tmp->valn = 'P';
	else if (vrbs->val_i == 0)
		tmp->valn = 'N';
	vrbs->val[0] = vrbs->val_i;
	vrbs->val[1] = '\0';
	if (!norme_help(tmp, vrbs))
		return (0);
	return (1);
}
