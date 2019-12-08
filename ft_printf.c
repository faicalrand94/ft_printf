/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:13:31 by fbouibao          #+#    #+#             */
/*   Updated: 2019/11/21 17:13:35 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char  *to_up(char *str)
{
  int i;

  i = -1;
  while (str[++i] != '\0')
    str[i] = ft_toupper(str[i]);
  return (str);
}
void str_spf_c(va_list ap, t_list *tmp)
{
  char *flgs;
  char flg;
  char *width;
  //char *prec;
  int i = -1;
  int a = 0, start;

  flgs = tmp->flg;
  if (flgs[0] == '\0')
  {
    tmp->str = ft_itos(va_arg(ap, int));
    return ;
  }
  while (flgs[++i] == '-')
    flg = '-';
  start = i;
  if (flgs[i] == '*')
    width = ft_strdup("*");
  else if (ft_isdigit(flgs[i]))
  {
    while (ft_isdigit(flgs[i]))
      i++;
    width = ft_substr(flgs, start, i - start );  
  }
  else
    width = ft_strdup("\0");
  if (width[0] == '*' && flg == '-')
  {
    a = va_arg(ap, int);
    if (a < 0)
      a = a * (-1);
    tmp->str = malloc(a + 1);
    tmp->str = memset(tmp->str, ' ', a);
    tmp->str[0] = (char)va_arg(ap, int);
  }
  else if (width[0] == '*')
  {

    a = va_arg(ap, int);
    if (a < 0)
      tmp->str = malloc((-1 * a) + 1);
    else
      tmp->str = malloc(a + 1);
    if (a < 0)
    {
      tmp->str = memset(tmp->str, ' ', (-1 * a));
      tmp->str[0] = (char)va_arg(ap, int);
    }
    else
    {
      tmp->str = memset(tmp->str, ' ', a);
      tmp->str[a - 1] = (char)va_arg(ap, int);
    }
  }
  else
  {
    if (flg == '\0')
    {
      tmp->str = malloc(atoi(width) + 1);
      tmp->str = memset(tmp->str, ' ', atoi(width));
      tmp->str[atoi(width) - 1] = (char)va_arg(ap, int);
    }
    else if (flg == '-')
    {
      tmp->str = malloc(atoi(width) + 1);
      tmp->str = memset(tmp->str, ' ', atoi(width));
      tmp->str[0] = (char)va_arg(ap, int);
    }
  }
}




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
    width = ft_strdup("\0");

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
  if (pos == 0)
    return (str);
  str[pos] = '0';
  str[0] = '-';
  return (str);
}

void str_spf_d(va_list ap, t_list *tmp)
{
  char *flgs;
  char flg;
  char *width;
  char *val;
  char *prec;
  char *str_c;
  int i = -1, j;


  flgs = tmp->flg;
  if (flgs[0] == '\0')
  {
    tmp->str = ft_itoa(va_arg(ap, int));
    return ;
  }

  flg = cut_flg(flgs, &i);
  width = cut_width(ap, flgs, &i, &flg);
  prec = cut_prec(ap, flgs, &i);

  val = ft_itoa(va_arg(ap, int));

  
  // width


  if (width != '\0')
  {
    
    if ((int)ft_strlen(val) >= atoi(width))
      tmp->str = malloc(ft_strlen(val) + 1);
    else
      tmp->str = malloc(atoi(width) + 1);
  }

  if (flg == '0' && width != '\0')
    memset(tmp->str, '0', atoi(width));
  else if (width != '\0')
    memset(tmp->str, ' ', atoi(width));

  i = atoi(width) - 1;
  j = ft_strlen(val) - 1;
  if ((int)ft_strlen(val) >= atoi(width))
    while (j >= 0)
    {
      tmp->str[j] = val[j];
      j--;
    }
  else if (flg == '-')
  {
    i = 0;
    j = 0;
    while (i < (int)ft_strlen(val))
    {
      tmp->str[i++] = val[j];
      j++;
    }
  }
  else
    while (j >= 0)
    {
      tmp->str[i--] = val[j];
      j--;
    }
if (atoi(val) < 0)
  tmp->str = neg_nbr(tmp->str);
//end width


// prec

if (val[0] == '0' && atoi(prec) == 0)
{
  i = atoi(width);
  while (--i >= 0)
      tmp->str[i] = ' ';
}
else if (atoi(prec) >= 0)
{
  if ((int)ft_strlen(val) > atoi(prec))
  {
    i = -1;
    while (tmp->str[++i] == '0')
        tmp->str[i] = ' ';
  }
  else if (flg == '-' && (int)ft_strlen(val) < atoi(prec) && atoi(width) > atoi(prec))
  {
    //str_c = ft_strdup(tmp->str);
    //free(tmp->str);
    i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = malloc(atoi(prec) + 1);
    str_c[atoi(prec)] = '\0';
    i = atoi(prec);
    while (--i >= 0)
      str_c[i] = '0';
    i = atoi(prec);
    j = ft_strlen(val); 
    while (--j >= 0)
      str_c[--i] = val[j];
    i = -1;
    while (++i < atoi(prec))
      tmp->str[i] = str_c[i];

  }
  else if (atoi(width) >= atoi(prec))
  {
    i = ft_strlen(tmp->str);
    while (--i >= 0)
      if (i < atoi(width) - atoi(prec))
        tmp->str[i] = ' ';
  }
  else if (atoi(width) < atoi(prec))
  {
    str_c = ft_strdup(tmp->str);
    free(tmp->str);
    tmp->str = malloc(atoi(prec) + 1);
    tmp->str[atoi(prec)] = '\0';
    i = -1;
    while (++i < atoi(prec))
      tmp->str[i] = '0';
      j = ft_strlen(val);
    while (--j >= 0)
    {
      tmp->str[--i] = val[j];
    }
  }

// end prec
}



}

void    ft_printf(char *str, ...)
{ 
  va_list ap;
  t_list *ob = NULL;
  t_list *tmp;
  t_list *aff;
  get_ob(str, &ob);
    tmp = ob;
  va_start(ap, str);
  while (tmp)
  {
    if (tmp->spfx == 's')
      tmp->str = va_arg(ap, char*);
    else if (tmp->spfx == 'c')
    {
      str_spf_c(ap , tmp);
    }
    else if (tmp->spfx == 'd' || tmp->spfx == 'i')
    {
      str_spf_d(ap, tmp);
    }
    else if (tmp->spfx == 'u')
      tmp->str = ft_itoa(va_arg(ap, unsigned int));
    else if (tmp->spfx == 'p')
      tmp->str = ft_itoa_16(va_arg(ap, unsigned long long));
    else if (tmp->spfx == 'x')
      tmp->str = ft_itoa_long16(va_arg(ap, long));
    else if (tmp->spfx == 'X')
      tmp->str = to_up(ft_itoa_long16(va_arg(ap, long)));  
    else if (tmp->spfx == '%')
      tmp->str = strdup("%");
    tmp = tmp->next;
  }
  aff = ob;
  while (aff)
  {
    ft_putstr(aff->str);
    aff = aff->next;
  }
}