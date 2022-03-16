/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:42:32 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 16:33:34 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init_stack(int value, t_pointer head)
{
	t_pointer	new;

	new = malloc(sizeof(t_stack));
	if (new == 0)
		return (-1);
	new->data.value = value;
	if (head->rlink != NULL)
	{
		new->llink = head;
		new->rlink = head->rlink;
		head->rlink->llink = new;
		head->rlink = new;
	}
	else
	{
		head->rlink = new;
		head->top = new;
		new->llink = head;
		new->rlink = NULL;
	}
	head->count++;
	return (0);
}

int	push_stack(t_data data, t_pointer head)
{
	t_pointer	new;

	new = malloc(sizeof(t_stack));
	if (new == 0)
		return (-1);
	new->data = data;
	if (head->rlink == NULL)
	{
		head->rlink = new;
		head->top = head->rlink;
		new->llink = head;
	}
	else
	{
		head->top->rlink = new;
		new->llink = head->top;
		head->top = new;
	}
	new->rlink = NULL;
	head->count++;
	return (0);
}

t_data	pop(t_pointer head)
{
	t_pointer	tmp;
	t_data		data;

	tmp = head->top;
	data = tmp->data;
	head->top = tmp->llink;
	head->top->rlink = NULL;
	tmp->llink = NULL;
	free(tmp);
	tmp = NULL;
	head->count--;
	return (data);
}

t_pointer	free_stack(t_pointer head)
{
	t_pointer	p;
	t_pointer	tmp;

	p = head->top;
	while (p)
	{
		tmp = p;
		p = p->llink;
		free(tmp);
	}
	return (head);
}
