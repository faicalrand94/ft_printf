/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:27:17 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/23 23:08:30 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t    j;

    if (!s)
        return (NULL);
    if (start > strlen(s))
        len = 0;
    if (!(str = (char*)malloc(len + 1)))
        return (NULL);
    j = 0;
    while (s[start] != '\0' && len--)
    {
        str[j] = s[start];
        start++;
        j++;
    }
    str[j] = '\0';
    return (str);
}
