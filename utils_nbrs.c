/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:09:23 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:52:51 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width_cnt(t_list *tmp, t_vrs *vrbs)
{
	int	i;
	int	j;

	i = vrbs->width - 1;
	j = ft_strlen(vrbs->val);
	if ((int)ft_strlen(vrbs->val) >= vrbs->width)
		while (--j >= 0)
			tmp->str[j] = vrbs->val[j];
	else if (vrbs->flg == '-')
	{
		i = -1;
		j = 0;
		while (++i < (int)ft_strlen(vrbs->val))
			tmp->str[i] = vrbs->val[j++];
	}
	else
		while (--j >= 0)
			tmp->str[i--] = vrbs->val[j];
	if (ft_atoi(vrbs->val) < 0)
		if (!(tmp->str = neg_nbr(tmp->str)))
			return (0);
	return (1);
}

int	ft_width(t_list *tmp, t_vrs *vrbs)
{
	if ((int)ft_strlen(vrbs->val) >= vrbs->width)
	{
		free(tmp->str);
		if (!(tmp->str = malloc(ft_strlen(vrbs->val) + 1)))
			return (0);
		tmp->str[ft_strlen(vrbs->val)] = '\0';
	}
	else
	{
		free(tmp->str);
		if (!(tmp->str = malloc(vrbs->width + 1)))
			return (0);
		tmp->str[vrbs->width] = '\0';
	}
	if (vrbs->flg == '0')
		ft_memset(tmp->str, '0', vrbs->width);
	else
		ft_memset(tmp->str, ' ', vrbs->width);
	if (!(ft_width_cnt(tmp, vrbs)))
		return (0);
	return (1);
}
