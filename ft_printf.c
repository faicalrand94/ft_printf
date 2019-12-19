/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:13:31 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/19 21:21:30 by fbouibao         ###   ########.fr       */
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
// void str_spf_c(va_list ap, t_list *tmp)
// {  
//   char *flgs;
//   char flg;
//   char *width;
//   //char *prec;
//   int i = -1;
//   int a = 0;

//   flgs = tmp->flg;
//   flg = cut_flg(flgs, &i);
//   width = ft_strdup("hello");
//  // width = cut_width(ap, flgs, &i, &flg);
//   if (width[0] == '*' && flg == '-')
//   {
//     a = va_arg(ap, int);
//     if (a < 0)
//       a = a * (-1);
//     tmp->str = malloc(a + 1);
//     tmp->str = memset(tmp->str, ' ', a);
//     tmp->str[0] = (char)va_arg(ap, int);
//   }
//   else if (width[0] == '*')
//   {

//     a = va_arg(ap, int);
//     if (a < 0)
//       tmp->str = malloc((-1 * a) + 1);
//     else
//       tmp->str = malloc(a + 1);
//     if (a < 0)
//     {
//       tmp->str = memset(tmp->str, ' ', (-1 * a));
//       tmp->str[0] = (char)va_arg(ap, int);
//     }
//     else
//     {
//       tmp->str = memset(tmp->str, ' ', a);
//       tmp->str[a - 1] = (char)va_arg(ap, int);
//     }
//   }
//   else
//   {
//     if (flg == '\0')
//     {
//       tmp->str = malloc(atoi(width) + 1);
//       tmp->str = memset(tmp->str, ' ', atoi(width));
//       tmp->str[atoi(width) - 1] = (char)va_arg(ap, int);
//     }
//     else if (flg == '-')
//     {
//       tmp->str = malloc(atoi(width) + 1);
//       tmp->str = memset(tmp->str, ' ', atoi(width));
//       tmp->str[0] = (char)va_arg(ap, int);
//     }
//   }
// }





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
      str_spf_s(ap, tmp);
    else if (tmp->spfx == 'c')
      str_spf_c(ap , tmp);
    else if (tmp->spfx == 'd' || tmp->spfx == 'i')
      str_spf_d(ap, tmp);
    else if (tmp->spfx == 'u')
      str_spf_u(ap, tmp);
    else if (tmp->spfx == 'p')
      str_spf_p(ap, tmp);
    else if (tmp->spfx == 'x')
      str_spf_x(ap, tmp);
    else if (tmp->spfx == 'X')
    {
      str_spf_x(ap, tmp);
      tmp->str = to_up(tmp->str);
    }
    else if (tmp->spfx == '%')
      str_spf_pct(ap , tmp);
    tmp = tmp->next;
  }
  aff = ob;
  while (aff)
  {
    ft_putstr(aff->str);
    aff = aff->next;
  }
}