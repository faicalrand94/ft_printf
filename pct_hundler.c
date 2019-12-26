/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_hundler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:16:56 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:50:40 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	norme_help(t_list *tmp, t_vrs *vrbs)
{
	if (vrbs->width != -1)
		if (!(ft_width_str(tmp, vrbs)))
			return (0);
	free_vrbs(vrbs);
	return (1);
}

int			str_spf_pct(va_list ap, t_list *tmp)
{
	t_vrs	*vrbs;
	int		i;

	i = -1;
	if (!(vrbs = l_lstnew_vrbs()))
		return (0);
	if (!(vrbs->val = (char*)malloc(sizeof(char) * 2)))
		return (0);
	vrbs->val[0] = '%';
	vrbs->val[1] = '\0';
	vrbs->flgs = tmp->flg;
	if (vrbs->flgs[0] == '\0')
	{
		tmp->str = ft_strdup(vrbs->val);
		free_vrbs(vrbs);
		return (1);
	}
	vrbs->flg = cut_flg(vrbs->flgs, &i);
	if ((vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg)) == -2)
		return (0);
	if (!(tmp->str = ft_strdup(vrbs->val)))
		return (0);
	if (!norme_help(tmp, vrbs))
		return (0);
	return (1);
}
