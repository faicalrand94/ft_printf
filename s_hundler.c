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


char *get_s_p_s(char *val, int prec)
{
  char *str_c;
  int i;
 
  if (!(str_c = malloc(prec + 1)))
    return (NULL);
  str_c[prec] = '\0';
  i = -1;
  
  while (++i < (int)ft_strlen(val) && i < prec)
    str_c[i] = val[i];
  return (str_c);
}

void str_spf_s(va_list ap, t_list *tmp)
{
  char *flgs;
  char flg;
  int width;
  char *val;
  int prec;
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


if (width != -1)
{   
  if ((int)ft_strlen(val) >= width && prec == -1)
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
  if ((int)ft_strlen(val) >= width && prec == -1)
    while (j >= 0)
    {
      tmp->str[j] = val[j];
      j--;
    }
  else if ((int)ft_strlen(val) < width && flg == '-')
  {
    i = 0;
    j = 0;
    while (i < (int)ft_strlen(val))
    {
      tmp->str[i++] = val[j];
      j++;
    }
  }
  else if ((int)ft_strlen(val) < width)
    while (j >= 0)
    {
      tmp->str[i--] = val[j];
      j--;
    }
}
//end width

// prec
if (prec >= 0 && prec > width && width < (int)ft_strlen(val))
{
  str_c = get_s_p_s(val, prec);
  free(tmp->str);
  tmp->str = str_c;
}
else if (flg == '-' && prec >= 0)
{
  i = width;
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p_s(val, prec);
    i = -1;
    while (++i < (int)ft_strlen(str_c))
      tmp->str[i] = str_c[i];
}
else if (prec >= 0)
{
  i = width;
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p_s(val, prec);
    i = width;
    j = ft_strlen(str_c);
    while (--j >= 0)
      tmp->str[--i] = str_c[j];
}

//3
//1



// end prec


}
