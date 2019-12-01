/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_l_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:26:11 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/01 15:26:13 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

    node = (t_list*)malloc(sizeof(t_list));
    node->str = str;
    node->spfx = spfx[0];
    node->flg = flg;
    node->next = NULL;
    return (node);
}
