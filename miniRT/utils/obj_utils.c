/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:28:40 by sichoi            #+#    #+#             */
/*   Updated: 2022/06/17 17:28:41 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	obj_add(t_obj **lst, t_obj *new)
{
	t_obj	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}

t_obj	*obj_last(t_obj *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
