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
      tmp->str = ft_itos(va_arg(ap, int));
    else if (tmp->spfx == 'd' || tmp->spfx == 'i')
      tmp->str = ft_itoa(va_arg(ap, int));
    else if (tmp->spfx == 'u')
      tmp->str = ft_itoa(va_arg(ap, unsigned int));
    else if (tmp->spfx == 'p')
      tmp->str = ft_itoa_16(va_arg(ap, unsigned long long));
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



int main() 
{
 // char *fname = strdup("Faical");
  //char *lname = strdup("BOUIBAOUEN");
  int a = 5;
  ft_printf("0x%p\n",&a);
  printf("%p\n",&a);

//printf("%p\n",&a);


  return 0;
}