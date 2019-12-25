/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:20:22 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/25 18:43:23 by fbouibao         ###   ########.fr       */
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

static	char	*ft_i16(char *mod, int n, int i)
{
	char	*str;
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	str[j++] = hex_chr(n);
	k = i - 1;
	while (i--)
	{
		str[j] = hex_chr((int)mod[k] - 33);
		k--;
		j++;
	}
	free(mod);
	return (str);
}

char			*ft_itoa_16(size_t n)
{
	int		i;
	int		j;
	char	*mod;
	size_t	div;
	char	*s;

	i = 0;
	j = 0;
	div = n;
	while (div >= 16)
	{
		div = div / 16;
		i++;
	}
	if (!(mod = malloc((sizeof(char) * i) + 1)))
		return (NULL);
	mod[i] = '\0';
	while (n >= 16)
	{
		mod[j++] = (n % 16) + 33;
		n = n / 16;
	}
	s = ft_strdup(mod);
	free(mod);
	return (ft_i16(s, n, i));
}
