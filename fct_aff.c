/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:13:16 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/27 17:07:20 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	norme_help(t_list *node, int *rtp)
{
	if (node->valn == 'P')
	{
		ft_putchar(0);
		ft_putstr(node->str + 1);
		if (((int)ft_strlen(node->str) - 1) < 0)
			*rtp += ft_strlen(node->str);
		else
			*rtp += ft_strlen(node->str) - 1;
		(*rtp)++;
	}
	else if (node->valn == 'N')
	{
		node->str[ft_strlen(node->str) - 1] = '\0';
		ft_putstr(node->str);
		ft_putchar(0);
		*rtp += ft_strlen(node->str);
		(*rtp)++;
	}
	else
	{
		ft_putstr(node->str);
		*rtp += ft_strlen(node->str);
	}
}

int				fct_aff(t_list *node)
{
	int rtp;

	rtp = 0;
	while (node)
	{
		norme_help(node, &rtp);
		node = node->next;
	}
	return (rtp);
}
