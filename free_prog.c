/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:42:18 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/26 17:43:46 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_vrbs(vr_list *vrbs)
{
	if (vrbs->val)
		free(vrbs->val);
	if (vrbs->str_c)
		free(vrbs->str_c);
	free(vrbs);
}

void	free_obb(t_list *ob)
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
