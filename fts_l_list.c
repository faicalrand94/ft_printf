/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_l_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:26:11 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 20:54:14 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vrs	*l_lstnew_vrbs(void)
{
	t_vrs	*node;

	if (!(node = (t_vrs*)malloc(sizeof(t_vrs))))
		return (NULL);
	node->val = NULL;
	node->str_c = NULL;
	node->flgs = NULL;
	node->prec = -1;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*list;

	list = lst;
	while (list)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst == NULL)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}

t_list	*l_lstnew(char *str, char *spfx, char *flg)
{
	t_list	*node;

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
