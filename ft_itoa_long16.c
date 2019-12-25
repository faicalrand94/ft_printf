/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:47:21 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/25 18:53:28 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	hex_chr(int i)
{
	if (i > 9)
	{
		return (i + 87);
	}
	return (i + '0');
}

static	char	*ft_i16(char *mod, unsigned int div, int i)
{
	char	*strr;
	int		j;
	int		k;

	k = (div > 0) ? div : -1 * div;
	j = 0;
	if (!(strr = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	strr[i + 1] = '\0';
	strr[j++] = hex_chr(k);
	k = i - 1;
	while (i--)
	{
		strr[j] = hex_chr((int)mod[k] - 33);
		k--;
		j++;
	}
	free(mod);
	return (strr);
}

char			*ft_itoa_int16(unsigned int n, int i, int j)
{
	char			*mod;
	unsigned	int	div;
	char			*s;

	div = n;
	while (div >= 16)
	{
		div = div / 16;
		i++;
	}
	if (!(mod = malloc((sizeof(char) * i) + 1)))
		return (NULL);
	mod[i] = '\0';
	div = (n > 0) ? n : -1 * n;
	while (div >= 16)
	{
		mod[j] = (div % 16) + 33;
		div = div / 16;
		j++;
	}
	s = ft_strdup(mod);
	free(mod);
	return (ft_i16(s, div, i));
}
