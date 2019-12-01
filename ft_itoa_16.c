/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:20:22 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/01 15:20:25 by fbouibao         ###   ########.fr       */
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

static char *ft_i16(int *mod, int n, int i)
{
  char *str;
  int j;
  int k;
  
  k = 0;
  j = 0;
  str = malloc(sizeof(char) * (i + 2));
  str[i + 1] = '\0';
  str[j++] = hex_chr(n);
  k = i - 1;
  while (i--)
  {
    str[j] = hex_chr(mod[k]);
    k--;
    j++;
  
  }
  return (str);
}

char *ft_itoa_16(size_t n)
{
  int i = 0, j = 0, *mod;
  size_t div;

  div = n;
  while (div > 16)
  {
    div = div / 16;
    i++;
  }
  mod = malloc(sizeof(int) * i);
  
  
  while (n > 16)
  {
    mod[j] = n % 16;
    n = n / 16;
    j++;
  }
 
  return (ft_i16(mod, n, i));
}
