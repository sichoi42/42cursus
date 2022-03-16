/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:47:44 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 15:55:20 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*p;
	t_list	*tmp;

	p = *lst;
	if (p == NULL)
		p = new;
	else
	{
		tmp = p;
		p = new;
		new->next = tmp;
	}
	*lst = p;
}
