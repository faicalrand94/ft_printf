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
  char *width;
  char *val;
  char *prec;
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


if (atoi(width) != -1)
{
    
  if ((int)ft_strlen(val) >= atoi(width))
  {
    tmp->str = malloc(ft_strlen(val) + 1);
    tmp->str[ft_strlen(val)] = '\0';
  }
  else
  {
    tmp->str = malloc(atoi(width) + 1);
    tmp->str[atoi(width)] = '\0';
  }

    (flg == '0') ? memset(tmp->str, '0', atoi(width)) : memset(tmp->str, ' ', atoi(width));

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
}



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
    while (tmp->str[++i] == '0' || tmp->str[i] == '-')
      tmp->str[i] = ' ';
  }
  else if (flg == '-' && atoi(width) > atoi(prec))
  {
    i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p_u(val, prec);
    i = -1;
    j = atoi(prec);
    while (++i < j)
      tmp->str[i] = str_c[i];
  }
  else if (atoi(width) > atoi(prec))
  {
    i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p_u(val, prec);
    i = atoi(width);
    j = atoi(prec);
    while (--j >= 0)
      tmp->str[--i] = str_c[j];
  }
  else if (atoi(width) <= atoi(prec))
  {
    str_c = ft_strdup(tmp->str);
    free(tmp->str);
    i = atoi(prec);
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
if (u_val == 0 && atoi(prec) == 0 && (atoi(width) == 0 || atoi(width) == -1))
{
  free(tmp->str);
  tmp->str = ft_strdup("");
}

}
