/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:28:05 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 00:02:05 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_pointer head_a)
{
	t_pointer	tmp;

	if (head_a->count == 2)
		sa(head_a);
	else if (head_a->count > 2)
	{
		tmp = head_a->top;
		head_a->top = tmp->llink;
		tmp->llink = head_a;
		tmp->rlink = head_a->rlink;
		head_a->rlink->llink = tmp;
		head_a->rlink = tmp;
		head_a->top->rlink = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_pointer head_b)
{
	t_pointer	tmp;

	if (head_b->count == 2)
		sb(head_b);
	else if (head_b->count > 2)
	{
		tmp = head_b->top;
		head_b->top = tmp->llink;
		tmp->llink = head_b;
		tmp->rlink = head_b->rlink;
		head_b->rlink->llink = tmp;
		head_b->rlink = tmp;
		head_b->top->rlink = NULL;
		write(1, "rb\n", 3);
	}
}

void	rr(t_pointer head_a, t_pointer head_b)
{
	ra(head_a);
	rb(head_b);
}
