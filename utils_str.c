/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:57:00 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:52:40 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_s_p_s(char *val, int prec)
{
	char	*str_c;
	int		i;

	if (!(str_c = malloc(prec + 1)))
		return (NULL);
	str_c[prec] = '\0';
	i = -1;
	while (++i < (int)ft_strlen(val) && i < prec)
		str_c[i] = val[i];
	return (str_c);
}

void	ft_width_cnt_str(t_list *tmp, t_vrs *vrbs)
{
	int	i;
	int	j;

	i = vrbs->width - 1;
	j = ft_strlen(vrbs->val);
	if ((int)ft_strlen(vrbs->val) >= vrbs->width && vrbs->prec <= -1)
		while (--j >= 0)
			tmp->str[j] = vrbs->val[j];
	else if ((int)ft_strlen(vrbs->val) < vrbs->width && vrbs->flg == '-')
	{
		i = -1;
		j = 0;
		while (++i < (int)ft_strlen(vrbs->val))
			tmp->str[i] = vrbs->val[j++];
	}
	else if ((int)ft_strlen(vrbs->val) < vrbs->width)
		while (--j >= 0)
			tmp->str[i--] = vrbs->val[j];
}

int		ft_width_str(t_list *tmp, t_vrs *vrbs)
{
	if ((int)ft_strlen(vrbs->val) >= vrbs->width && vrbs->prec <= -1)
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
	ft_width_cnt_str(tmp, vrbs);
	return (1);
}
