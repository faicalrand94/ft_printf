/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:00:18 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/24 18:39:33 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *add_xo(char *s)
{
    int i;
    char *str;

    i = 1;
    if (!(str = malloc(ft_strlen(s) + 3)))
      return (NULL);
    str[ft_strlen(str) + 2] = '\0';
    str[0] = '0';
    str[1] = 'x';
    while (++i < (int)ft_strlen(str) + 2)
        str[i] = s[i - 2];
    free(s);
    return (str);
}

int str_spf_p(va_list ap, t_list *tmp)
{
  vr_list *vrbs;
  int i;

  i = -1;
  if (!(vrbs = l_lstnew_vrbs()))
    return (0);
  vrbs->flgs = tmp->flg;
  if (vrbs->flgs[0] == '\0')
  {
    if (!(tmp->str = add_xo(ft_itoa_16((size_t)va_arg(ap, size_t)))))
      return (0);
    free_vrbs(vrbs);
    return (1);
  }
  vrbs->flg = cut_flg(vrbs->flgs, &i);
  if ((vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg)) == -2)
		return (0);
	if ((vrbs->prec = cut_prec(ap, vrbs->flgs, &i)) == -2)
		return (0);
	if ((vrbs->st_val = va_arg(ap, size_t)) == 0 && vrbs->prec != -1)
	{
    if (!(vrbs->val = add_xo(ft_strdup(""))))
      return (0);
  }
	else
  	if (!(vrbs->val = add_xo(ft_itoa_16(vrbs->st_val))))
      return (0);

  if (!(tmp->str = ft_strdup(vrbs->val)))
    return (0);
  if (vrbs->width != -1)
    if (!(ft_width(tmp, vrbs)))
			return (0);
    free_vrbs(vrbs);
  return (1);
}
