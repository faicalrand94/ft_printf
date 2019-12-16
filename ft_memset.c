/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 01:06:48 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/16 01:06:52 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*scp;
	size_t	i;

	i = 0;
	if (n)
	{
		scp = (char*)str;
		while (i < n)
		{
			scp[i] = c;
			i++;
		}
	}
	return (str);
}
