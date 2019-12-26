/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmpl_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:11:52 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:52:56 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*to_up(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		str[i] = ft_toupper(str[i]);
	return (str);
}

static	int	norme_help(va_list ap, t_list *node)
{
	if (node->spfx == 'u')
	{
		if (!str_spf_u(ap, node))
			return (0);
	}
	else if (node->spfx == 'p')
	{
		if (!str_spf_p(ap, node))
			return (0);
	}
	else if (node->spfx == 'x')
	{
		if (!str_spf_x(ap, node))
			return (0);
	}
	else if (node->spfx == 'X')
	{
		if (!str_spf_x(ap, node))
			return (0);
		node->str = to_up(node->str);
	}
	else if (node->spfx == '%')
		if (!str_spf_pct(ap, node))
			return (0);
	return (1);
}

int			rmpl_node(va_list ap, t_list *node)
{
	while (node)
	{
		if (node->spfx == 's')
		{
			if (!str_spf_s(ap, node))
				return (0);
		}
		else if (node->spfx == 'c')
		{
			if (!str_spf_c(ap, node))
				return (0);
		}
		else if (node->spfx == 'd' || node->spfx == 'i')
		{
			if (!str_spf_d(ap, node))
				return (0);
		}
		else if (!(norme_help(ap, node)))
			return (0);
		node = node->next;
	}
	return (1);
}
