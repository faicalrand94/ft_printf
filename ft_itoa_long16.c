/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:56:08 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/01 17:56:11 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char hex_chr(int i)
{
  if (i > 9)
  {
    return (i + 87);
  }
  return (i + '0');
}

static char *ft_i16(int *mod,unsigned int div, int i)
{
  char *str;
  int j;
  int k;
  
  
  k = (div > 0) ? div : -1 * div;
  j = 0;
  str = malloc(sizeof(char) * (i + 2));
  str[i + 1] = '\0';
  str[j++] = hex_chr(k);
  k = i - 1;
  while (i--)
  {
    str[j] = hex_chr(mod[k]);
    k--;
    j++;
  
  }
  return (str);
}

char *ft_itoa_int16(unsigned int n)
{
  int i = 0, j = 0, *mod;
  unsigned int div;

  div = n;
  while (div >= 16)
  {
    div = div / 16;
    i++;
  }
  mod = malloc(sizeof(int) * i);
  
  div = (n > 0) ? n : -1 * n;
  while (div >= 16)
  {
    mod[j] = div % 16;
    div = div / 16;
    j++;
  }
 
  return (ft_i16(mod, div, i));
}
