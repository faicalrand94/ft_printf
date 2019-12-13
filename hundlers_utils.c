/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundlers_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:35:11 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/10 16:35:13 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char cut_flg(char *flgs, int *i)
{
  char flg;

  if (flgs[++(*i)] == '-')
    while (flgs[(*i)] == '-')
    {
        flg = '-';
        (*i)++;
    }
  else if (flgs[(*i)] == '0')
    while (flgs[(*i)] == '0')
    {
        flg = '0';
        (*i)++;
    }
  else 
    flg = '\0';
  return (flg);
}


char *cut_width(va_list ap, char *flgs, int *i, char *flg)
{
  int start;
  char *width;
  int val;

  start = *i;
  if (flgs[(*i)] == '*')
  {
    val = va_arg(ap, int);
    if (val >= 0)
      width = ft_itoa(val);
    else
    {
      width = ft_itoa(-1 * val);
      *flg = '-';
    }
    (*i)++;
  }
  else if (ft_isdigit(flgs[(*i)]))
  {
    while (ft_isdigit(flgs[(*i)]))
      (*i)++;
    width = ft_substr(flgs, start, (*i) - start );  
  }
  else
    width = ft_strdup("-1");

    return (width);
}

char *cut_prec(va_list ap, char *flgs, int *i)
{
  int start;
  char *prec;

  prec = ft_strdup("0");
  if (flgs[(*i)] == '.')
  {
    (*i)++;
    if (flgs[(*i)] == '*')
    {
      prec = ft_itoa(va_arg(ap, int));
      (*i)++;
    }
    else if (ft_isdigit(flgs[(*i)]))
    {
      start = (*i);
      while (ft_isdigit(flgs[(*i)]))
        (*i)++;
      prec = ft_substr(flgs, start, (*i) - start );  
    }  
  }
  else if (flgs[(*i)] != '.')
    prec = ft_strdup("-1");
  return (prec);
}

char  *neg_nbr(char *str)
{
  int i;
  int pos;

  pos = 0;
  i = -1;
  while (str[++i] != '\0')
    if (str[i] == '-')
    {
      pos = i;
      break;
    }
  if (pos == 0 || !ft_isdigit(str[pos - 1]))
    return (str);
  str[pos] = '0';
  str[0] = '-';
  return (str);
}

char *get_s_p(char *val, char *prec)
{
  char *str_c;
  int i;
  int j;

  str_c = NULL;
  if (atoi(val) > 0)
  {
    str_c = malloc(atoi(prec) + 1);
    str_c[atoi(prec)] = '\0';
    i = atoi(prec);
  }
  else
  {
    str_c = malloc(atoi(prec) + 2);
    str_c[atoi(prec) + 1] = '\0';
    i = atoi(prec) + 1;
  }
        while (--i >= 0)
            str_c[i] = '0';
  i = (atoi(val) > 0) ? atoi(prec) : atoi(prec) + 1;
  j = ft_strlen(val); 
  while (--j >= 0)
    str_c[--i] = val[j];
    if (atoi(val) < 0)
      str_c = neg_nbr(str_c);
  return (str_c);
}

char *get_s_p_u(char *val, char *prec)
{
  char *str_c;
  int i;
  int j;

  str_c = NULL;
  str_c = malloc(atoi(prec) + 1);
  str_c[atoi(prec)] = '\0';
  i = atoi(prec);
  while (--i >= 0)
      str_c[i] = '0';
  i = atoi(prec);
  j = ft_strlen(val); 
  while (--j >= 0)
    str_c[--i] = val[j];
  return (str_c);
}