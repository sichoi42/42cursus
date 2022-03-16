/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:31:16 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 16:33:43 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_digit(const char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			flag = -1;
		if (s[0] == '-' || s[0] == '+')
			flag = 0;
		i++;
	}
	return (flag);
}

int	is_sorted(t_pointer head)
{
	t_pointer	p;
	t_pointer	comp;
	int			return_val;

	return_val = 0;
	p = head->top;
	while (p != head)
	{
		comp = p->llink;
		while (comp != head)
		{
			if (comp->data.value < p->data.value)
				return_val = -1;
			else if (comp->data.value == p->data.value)
				return (-2);
			comp = comp->llink;
		}
		p = p->llink;
	}
	return (return_val);
}

void	get_rank(t_pointer head)
{
	t_pointer	p;
	t_pointer	next;

	p = head->top;
	while (p != head)
	{
		next = head->top;
		while (next != head)
		{
			if (p->data.value > next->data.value)
				p->data.rank++;
			next = next->llink;
		}
		p = p->llink;
	}
}

void	init_rank(t_pointer head_a, t_pointer head_b)
{
	t_pointer	p;

	if (head_a->count != 0)
	{
		p = head_a->top;
		while (p != head_a)
		{
			p->data.rank = 0;
			p = p->llink;
		}
	}
	if (head_b->count != 0)
	{
		p = head_b->top;
		while (p != head_b)
		{
			p->data.rank = 0;
			p = p->llink;
		}
	}
}
