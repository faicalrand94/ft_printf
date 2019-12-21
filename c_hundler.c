/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:55:18 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/20 22:56:56 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_spf_c(va_list ap, t_list *tmp)
{
	vr_list	*vrbs;
	int		i;

	i = -1;
	if (!(vrbs = l_lstnew_vrbs()))
		return (0);
	vrbs->flgs = tmp->flg;
	if (!(vrbs->val = (char*)malloc(sizeof(char) * 2)))
		return (0);
	vrbs->val[0] = (char)va_arg(ap, int);
	vrbs->val[1] = '\0';
	if (vrbs->flgs[0] == '\0')
	{
		tmp->str = vrbs->val;
		return (1);
	}
	vrbs->flg = cut_flg(vrbs->flgs, &i);
	if ((vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg)) == -2)
		return (0);
	
	if (!(tmp->str = ft_strdup(vrbs->val)))
		return (0);
	if (vrbs->width != -1)  
		if (!(ft_width_str(tmp, vrbs)))
			return (0);
	return (1);
}
