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
void	ft_width_cnt_str(t_list *tmp, vr_list *vrbs)
{
	int	i;
	int	j;

	i = vrbs->width - 1;
  j = ft_strlen(vrbs->val);
  if ((int)ft_strlen(vrbs->val) >= vrbs->width && vrbs->prec == -1)
    while (--j >= 0)
      tmp->str[j] = vrbs->val[j];
  else if ((int)ft_strlen(vrbs->val) < vrbs->width && vrbs->flg == '-')
  {
    i = -1;
    j = 0;
    while (++i < (int)ft_strlen(vrbs->val))
      tmp->str[i] = vrbs->val[j++];
  }
  else if ((int)ft_strlen(vrbs->val) < vrbs->width)
    while (--j >= 0)
      tmp->str[i--] = vrbs->val[j];
}

int   ft_width_str(t_list *tmp, vr_list *vrbs)
{
	if ((int)ft_strlen(vrbs->val) >= vrbs->width && vrbs->prec == -1)
  {
    tmp->str = malloc(ft_strlen(vrbs->val) + 1);
    tmp->str[ft_strlen(vrbs->val)] = '\0';
  }
  else
  {
    tmp->str = malloc(vrbs->width + 1);
    tmp->str[vrbs->width] = '\0';
  }
  ft_memset(tmp->str, ' ', vrbs->width);
  ft_width_cnt_str(tmp, vrbs);
  return (1);
}

static int	ft_prec_cnt_str(t_list *tmp, vr_list *vrbs)
{
  int i;
  int j;

  i = vrbs->width;
  while (--i >= 0)
      tmp->str[i] = ' ';
  vrbs->str_c = get_s_p_s(vrbs->val, vrbs->prec);
  if (vrbs->flg == '-')
  {
    i = -1;
    while (++i < (int)ft_strlen(vrbs->str_c))
      tmp->str[i] = vrbs->str_c[i];
  }
  else
  {
    i = vrbs->width;
    j = ft_strlen(vrbs->str_c);
    while (--j >= 0)
    tmp->str[--i] = vrbs->str_c[j];
  }
  return (1);
}

int str_spf_s(va_list ap, t_list *tmp)
{
  vr_list *vrbs;
  int i;


  i = -1;
  vrbs = l_lstnew_vrbs();
  vrbs->flgs = tmp->flg;
  if (vrbs->flgs[0] == '\0')
  {
    tmp->str = va_arg(ap, char*);
    return (1);
  }
  vrbs->flg = cut_flg(vrbs->flgs, &i);
	vrbs->width = cut_width(ap, vrbs->flgs, &i, &vrbs->flg);
	vrbs->prec = cut_prec(ap, vrbs->flgs, &i);
  vrbs->val = va_arg(ap, char*);
  tmp->str = ft_strdup(vrbs->val);
  if (vrbs->width != -1)  
    ft_width_str(tmp, vrbs);
  if (vrbs->prec >= 0 && vrbs->prec > vrbs->width && vrbs->width < (int)ft_strlen(vrbs->val))
  {
    vrbs->str_c = get_s_p_s(vrbs->val, vrbs->prec);
    free(tmp->str);
    tmp->str = vrbs->str_c;
  }
  else if (vrbs->prec >= 0)
    ft_prec_cnt_str(tmp, vrbs);
  return (1);
}
