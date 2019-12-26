/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:28:59 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:53:24 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int cpt;

	cpt = 0;
	if (!str)
		return (0);
	while (str[cpt] != '\0')
	{
		cpt++;
	}
	return (cpt);
}
