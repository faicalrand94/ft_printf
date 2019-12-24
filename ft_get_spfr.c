/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spfr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:25:07 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/24 18:23:38 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_spf(int pos, char* str)
{
  int i;  
  char *s;

  i = 0;
  s = ft_strdup("cspdiuxX%");
  while (str[pos])
  {
    while (s[i])
    {
      if (str[pos] == s[i])
      {
        free(s);
        return (pos);
      }
      i++;
    }
    i = 0;
    pos++;
  }
  free(s);
  return (0);
  
}
