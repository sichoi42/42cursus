/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:47:14 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 00:01:15 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_pointer head_a)
{
	t_pointer	tmp;

	if (head_a->count == 2)
		sa(head_a);
	else if (head_a->count > 2)
	{
		tmp = head_a->rlink;
		head_a->rlink = tmp->rlink;
		tmp->rlink->llink = head_a;
		head_a->top->rlink = tmp;
		tmp->llink = head_a->top;
		head_a->top = tmp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_pointer head_b)
{
	t_pointer	tmp;

	if (head_b->count == 2)
		sb(head_b);
	else if (head_b->count > 2)
	{
		tmp = head_b->rlink;
		head_b->rlink = tmp->rlink;
		tmp->rlink->llink = head_b;
		head_b->top->rlink = tmp;
		tmp->llink = head_b->top;
		head_b->top = tmp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_pointer head_a, t_pointer head_b)
{
	rra(head_a);
	rrb(head_b);
}
