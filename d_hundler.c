/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:30:53 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/10 16:30:57 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void str_spf_d(va_list ap, t_list *tmp)
{
  char *flgs;
  char flg;
  int width;
  char *val;
  int prec;
  char *str_c;
  int i = -1, j;
  int val_i;


  flgs = tmp->flg;
  if (flgs[0] == '\0')
  {
    tmp->str = ft_itoa(va_arg(ap, int));
    return ;
  }

  flg = cut_flg(flgs, &i);
  width = cut_width(ap, flgs, &i, &flg);
  prec = cut_prec(ap, flgs, &i);

  val_i = va_arg(ap, int);
  val = ft_itoa(val_i);

  tmp->str = ft_strdup(val);
  // width


if (width != -1)
{
    
  if ((int)ft_strlen(val) >= width)
  {
    tmp->str = malloc(ft_strlen(val) + 1);
    tmp->str[ft_strlen(val)] = '\0';
  }
  else
  {
    tmp->str = malloc(width + 1);
    tmp->str[width] = '\0';
  }

    (flg == '0') ? memset(tmp->str, '0', width) : memset(tmp->str, ' ', width);

  i = width - 1;
  j = ft_strlen(val) - 1;
  if ((int)ft_strlen(val) >= width)
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
  if (val_i < 0)
    tmp->str = neg_nbr(tmp->str);
}



//end width

// prec

if (val[0] == '0' && prec == 0)
{
  i = width;
  while (--i >= 0)
      tmp->str[i] = ' ';
}
else if (prec >= 0)
{
  if ((int)ft_strlen(val) > prec)
  {
    i = -1;
    while (tmp->str[++i] == '0' || tmp->str[i] == '-')
      tmp->str[i] = ' ';
    if (val_i < 0)
      tmp->str[--i] = '-';
  }
  else if (flg == '-' && width > prec)
  {
    i = width;
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p(val, prec);
    i = -1;
    j = (val_i > 0) ? prec : prec + 1;
    while (++i < j)
      tmp->str[i] = str_c[i];
  }
  else if (width > prec)
  {
    i = width;
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p(val, prec);
    i = width;
    j = (val_i >= 0) ? prec : prec + 1;
    while (--j >= 0)
      tmp->str[--i] = str_c[j];
  }
  else if (width <= prec)
  {
    str_c = ft_strdup(tmp->str);
    free(tmp->str);
    i = (val_i > 0) ? prec : prec + 1;
    tmp->str = malloc(i + 1);
    tmp->str[i] = '\0';
    
    j = -1;
    while (++j < i)
      tmp->str[j] = '0';
      j = ft_strlen(val);
    while (--j >= 0)
    {
      tmp->str[--i] = val[j];
    }
    if (val_i < 0)
      tmp->str = neg_nbr(tmp->str);
  }


}
// end prec
if (val[0] == '0' && prec == 0 && (width == 0 || width == -1))
{
  free(tmp->str);
  tmp->str = ft_strdup("");
}

}