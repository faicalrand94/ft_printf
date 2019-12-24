/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_l_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:26:11 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/24 18:22:14 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

vr_list        *l_lstnew_vrbs()
{
    vr_list    *node;

    if (!(node = (vr_list*)malloc(sizeof(vr_list))))
        return (NULL);
    node->val = NULL;
    node->str_c = NULL;
    node->flgs = NULL;
    node->prec = -1;
    return (node);
}



t_list    *ft_lstlast(t_list *lst)
{
    t_list    *list;

    list = lst;
    while (list)
    {
        if (list->next == NULL)
            return (list);
        list = list->next;
    }
    return (NULL);
}

void    ft_lstadd_back(t_list **alst, t_list *new)
{
    if (*alst == NULL)
        *alst = new;
    else
        ft_lstlast(*alst)->next = new;
}

t_list        *l_lstnew(char *str,char *spfx, char *flg)
{
    t_list    *node;

    if (!(node = (t_list*)malloc(sizeof(t_list))))
        return (NULL);
    node->str = str;
    node->spfx = spfx[0];
    free(spfx);
    node->flg = flg;
    node->valn = 1;
    node->next = NULL;
    return (node);
}

void	free_vrbs(vr_list *vrbs)
{
	if (vrbs->val)
		free(vrbs->val);
	if (vrbs->str_c)
		free(vrbs->str_c);
	free(vrbs);
}

void free_obb(t_list *ob)
{
  t_list *f;

  if ((f = ob))
    ob = ob->next;
  while (f)
  {
    free(f->flg);
    free(f->str);
    free(f);
    if ((f = ob))
      ob = ob->next;
  }
}
