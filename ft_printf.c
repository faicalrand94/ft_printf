/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:13:31 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 15:17:58 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list	ap;
	t_list	*node;
	int		rtp;

	node = NULL;
	get_node(str, &node);
	va_start(ap, str);
	if (!(rmpl_node(ap, node)))
		return (-1);
	rtp = fct_aff(node);
	free_obb(node);
	return (rtp);
}
