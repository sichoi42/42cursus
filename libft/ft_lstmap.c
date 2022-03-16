/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:36:55 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 16:09:21 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*tmp;
	t_list	*p;

	if (l == NULL)
		return (NULL);
	p = NULL;
	while (l)
	{
		tmp = ft_lstnew((*f)(l->content));
		if (tmp == NULL)
		{
			ft_lstclear(&p, d);
			break ;
		}
		ft_lstadd_back(&p, tmp);
		tmp = tmp->next;
		l = l->next;
	}
	return (p);
}
