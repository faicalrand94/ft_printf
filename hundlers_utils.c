/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundlers_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:35:11 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/24 15:04:28 by fbouibao         ###   ########.fr       */
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


int cut_width(va_list ap, char *flgs, int *i, char *flg)
{
  int start;
  char *width;
  int val;

  start = *i;
  if (flgs[(*i)] == '*')
  {
    val = va_arg(ap, int);
    if (val >= 0)
    {
      if(!(width = ft_itoa(val)))
        return (-2);
    }
    else
    {
      if(!(width = ft_itoa(-1 * val)))
        return (-2);
      *flg = '-';
    }
    (*i)++;
  }
  else if (ft_isdigit(flgs[(*i)]))
  {
    while (ft_isdigit(flgs[(*i)]))
      (*i)++;
    if (!(width = ft_substr(flgs, start, (*i) - start )))
      return (-2);
  }
  else
    if (!(width = ft_strdup("-1")))
      return (-2);
    val = ft_atoi(width);
    free(width);
    return (val);
}

int cut_prec(va_list ap, char *flgs, int *i)
{
  int start;
  char *prec;

  if (!(prec = ft_strdup("0")))
    return (-2);
  if (flgs[(*i)] == '.')
  {
    (*i)++;
    if (flgs[(*i)] == '*')
    { 
      free(prec);
      if (!(prec = ft_itoa(va_arg(ap, int))))
        return (-2);
      (*i)++;
    }
    else if (ft_isdigit(flgs[(*i)]))
    {
      start = (*i);
      while (ft_isdigit(flgs[(*i)]))
        (*i)++;
      free(prec);
      if (!(prec = ft_substr(flgs, start, (*i) - start)))
        return (-2);  
    }  
  }
  else if (flgs[(*i)] != '.')
  {
    free(prec);
    if (!(prec = ft_strdup("-1")))
      return (-2);
  }
  start = ft_atoi(prec);
  free(prec);
  return (start);
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

char *get_s_p(char *val, int prec)
{
  char *str_c;
  int i;
  int j;

  str_c = NULL;
  if (atoi(val) > 0)
  {
    if (!(str_c = malloc(prec + 1)))
      return (NULL);
    str_c[prec] = '\0';
    i = prec;
  }
  else
  {
    if (!(str_c = malloc(prec + 2)))
      return (NULL);
    str_c[prec + 1] = '\0';
    i = prec + 1;
  }
        while (--i >= 0)
            str_c[i] = '0';
  i = (atoi(val) > 0) ? prec : prec + 1;
  j = ft_strlen(val); 
  while (--j >= 0)
    str_c[--i] = val[j];
    if (atoi(val) < 0)
      str_c = neg_nbr(str_c);
  return (str_c);
}

char *get_s_p_u(char *val, int prec)
{
  char *str_c;
  int i;
  int j;

  str_c = NULL;
  if (!(str_c = malloc(prec + 1)))
    return (NULL);
  str_c[prec] = '\0';
  i = prec;
  while (--i >= 0)
      str_c[i] = '0';
  i = prec;
  j = ft_strlen(val); 
  while (--j >= 0)
    str_c[--i] = val[j];
  return (str_c);
}
