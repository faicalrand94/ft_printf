/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:13:31 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/20 22:09:04 by fbouibao         ###   ########.fr       */
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

int    ft_printf(char *str, ...)
{ 
  va_list ap;
  t_list *ob = NULL;
  t_list *tmp;
  t_list *aff;
  int rtp;

  rtp = 0;
  get_ob(str, &ob);
    tmp = ob;
  va_start(ap, str);
  while (tmp)
  {
    if (tmp->spfx == 's')
    {  
      if(!str_spf_s(ap, tmp))
        return (-1);
    }
    else if (tmp->spfx == 'c')
    {  
      if(!str_spf_c(ap, tmp))
        return (-1);
    }
    else if (tmp->spfx == 'd' || tmp->spfx == 'i')
    {  
      if(!str_spf_d(ap, tmp))
        return (-1);
    }
    else if (tmp->spfx == 'u')
    {  
      if(!str_spf_u(ap, tmp))
        return (-1);
    }
    else if (tmp->spfx == 'p')
    {  
      if(!str_spf_p(ap, tmp))
        return (-1);
    }
    else if (tmp->spfx == 'x')
    {  
      if(!str_spf_x(ap, tmp))
        return (-1);
    }
    else if (tmp->spfx == 'X')
    {
      if(!str_spf_x(ap, tmp))
        return (-1);
      tmp->str = to_up(tmp->str);
    }
    else if (tmp->spfx == '%')
      if(!str_spf_pct(ap, tmp))
        return (-1);
    tmp = tmp->next;
  }
  aff = ob;

  while (aff)
  {
    rtp += ft_strlen(aff->str);
    ft_putstr(aff->str);
    aff = aff->next;
  }
  return (rtp);
}
