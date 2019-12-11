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
    {
      str_spf_s(ap, tmp);
    }
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