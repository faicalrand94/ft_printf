/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:54:39 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/13 17:54:47 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void str_spf_x(va_list ap, t_list *tmp)
{
  char *flgs;
  char flg;
  int width;
  char *val;
  int prec;
  char *str_c;
  int i = -1, j;
  unsigned int u_val;


  flgs = tmp->flg;
  if (flgs[0] == '\0')
  {
    tmp->str = ft_itoa((unsigned int)va_arg(ap, unsigned int));
    return ;
  }

  flg = cut_flg(flgs, &i);
  width = cut_width(ap, flgs, &i, &flg);
  prec = cut_prec(ap, flgs, &i);
  u_val = va_arg(ap, unsigned int);
  val = ft_itoa_int16(u_val);

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
  }
  else if (flg == '-' && width > prec)
  {
    i = width;
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p_u(val, prec);
    i = -1;
    j = prec;
    while (++i < j)
      tmp->str[i] = str_c[i];
  }
  else if (width > prec)
  {
    i = width;
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p_u(val, prec);
    i = width;
    j = prec;
    while (--j >= 0)
      tmp->str[--i] = str_c[j];
  }
  else if (width <= prec)
  {
    str_c = ft_strdup(tmp->str);
    free(tmp->str);
    i = prec;
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
  }


}
// end prec
if (u_val == 0 && prec == 0 && (width == 0 || width == -1))
{
  free(tmp->str);
  tmp->str = ft_strdup("");
}

}
