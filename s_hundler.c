/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:43:14 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/10 16:45:19 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void str_spf_s(va_list ap, t_list *tmp)
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
    tmp->str = va_arg(ap, char*);
    return ;
  }

  flg = cut_flg(flgs, &i);
  width = cut_width(ap, flgs, &i, &flg);
  prec = cut_prec(ap, flgs, &i);

  val = va_arg(ap, char*);

  
  // width


if (width != '\0')
{
    tmp->str = ((int)ft_strlen(val) >= atoi(width) && atoi(prec) == -1) ? malloc(ft_strlen(val) + 1) : malloc(atoi(width) + 1);

    (flg == '0') ? memset(tmp->str, '0', atoi(width)) : memset(tmp->str, ' ', atoi(width));

  i = atoi(width) - 1;
  j = ft_strlen(val) - 1;
  if ((int)ft_strlen(val) >= atoi(width) && atoi(prec) == -1)
    while (j >= 0)
    {
      tmp->str[j] = val[j];
      j--;
    }
  else if (flg == '-' && atoi(prec) == -1)
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
}
//end width

// prec
if (flg == '-' && atoi(prec) >= 0)
{
  i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p(val, prec, 0);
    i = -1;
    j = atoi(prec);
    while (--j >= 0)
      tmp->str[i] = str_c[j];
}
else if (atoi(prec) >= 0)
{
  i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p(val, prec, 0);
    i = atoi(width);
    j = atoi(prec);
    while (--j >= 0)
      tmp->str[--i] = str_c[j];
}
else if (atoi(prec) >= 0)
{
  if ((int)ft_strlen(val) > atoi(prec))
  {
    i = -1;
    while (tmp->str[++i] == '0' || tmp->str[i] == '-')
      tmp->str[i] = ' ';
    if (atoi(val) < 0)
      tmp->str[--i] = '-';
  }
  else if (flg == '-' && atoi(width) > atoi(prec))
  {
    i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p(val, prec, 0);
    i = -1;
    j = (atoi(val) > 0) ? atoi(prec) : atoi(prec) + 1;
    while (++i < j)
      tmp->str[i] = str_c[i];
  }
  else if (atoi(width) > atoi(prec))
  {
    i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p(val, prec, 0);
    i = atoi(width);
    j = (atoi(val) >= 0) ? atoi(prec) : atoi(prec) + 1;
    while (--j >= 0)
      tmp->str[--i] = str_c[j];
  }
  else if (atoi(width) <= atoi(prec))
  {
    str_c = ft_strdup(tmp->str);
    free(tmp->str);
    i = (atoi(val) > 0) ? atoi(prec) : atoi(prec) + 1;
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
    if (atoi(val) < 0)
      tmp->str = neg_nbr(tmp->str);
  }


}
// end prec
if (val[0] == '0' && atoi(prec) == 0 && atoi(width) == 0)
{
  free(tmp->str);
  tmp->str = ft_strdup("");
}

}
