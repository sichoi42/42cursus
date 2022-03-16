/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:50:10 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 16:02:54 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_pointer head)
{
	t_data	data;

	data = head->top->data;
	head->top->data = head->top->llink->data;
	head->top->llink->data = data;
}

void	sa(t_pointer head_a)
{
	swap(head_a);
	write(1, "sa\n", 3);
}

void	sb(t_pointer head_b)
{
	swap(head_b);
	write(1, "sb\n", 3);
}

void	ss(t_pointer head_a, t_pointer head_b)
{
	sa(head_a);
	sb(head_b);
}
