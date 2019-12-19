/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:55:18 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/19 21:13:24 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_spf_c(va_list ap, t_list *tmp)
{
	vr_list	*vrbs;
	int		i;

	i = -1;
	vrbs = l_lstnew_vrbs();
	vrbs->flgs = tmp->flg;
	if (vrbs->flgs[0] == '\0')
	{
		tmp->str = va_arg(ap, char*);
		return (1);
	}
	vrbs->flg = cut_flg(vrbs->flgs, &i);
	vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg);
	vrbs->val = (char*)malloc(sizeof(char) * 2);
	vrbs->val[0] = (char)va_arg(ap, int);
	vrbs->val[1] = '\0';
	tmp->str = ft_strdup(vrbs->val);
	if (vrbs->width != -1)  
		ft_width_str(tmp, vrbs);
	return (1);
}
