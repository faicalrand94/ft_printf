/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:22:23 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 17:35:56 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_node(char *str, t_list **ob)
{
	int		i;
	int		start;
	int		r_sp;
	char	*spfr;
	char	*flgs;

	i = -1;
	start = 0;
	while (str[++i] != '\0')
		if (str[i + 1] == '%' || str[i + 1] == '\0' || str[i] == '%')
		{
			if ((str[i + 1] == '%' || str[i + 1] == '\0') && str[i] != '%')
				ft_lstadd_back(ob, l_lstnew(ft_substr(str, start, i - start + 1)
							, ft_strdup("\0"), ft_strdup("\0")));
			if (str[i] == '%')
				if ((r_sp = get_spf(i + 1, str)) != 0)
				{
					spfr = ft_substr(str, r_sp, 1);
					flgs = ft_substr(str, (i + 1), r_sp - i - 1);
					ft_lstadd_back(ob, l_lstnew(NULL, spfr, flgs));
					i = r_sp;
					start = r_sp + 1;
				}
		}
}
