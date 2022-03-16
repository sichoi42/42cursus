/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:18:09 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 16:32:55 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorting(t_pointer head_a)
{
	t_pointer	head_b;

	head_b = malloc(sizeof(t_stack));
	if (head_b == 0)
		return (-1);
	head_b->llink = NULL;
	head_b->rlink = NULL;
	get_rank(head_a);
	if (head_a->count == 2)
		sa(head_a);
	else if (head_a->count == 3)
		sorting_three(head_a, head_b);
	else if (head_a->count == 4)
		sorting_four(head_a, head_b);
	else if (head_a->count == 5)
		sorting_five(head_a, head_b);
	else
		radix_sort(head_a, head_b);
	head_b = free_stack(head_b);
	return (0);
}

void	radix_sort(t_pointer head_a, t_pointer head_b)
{
	int	i;
	int	j;
	int	count;
	int	max_num;
	int	max_len;

	max_num = head_a->count - 1;
	max_len = 0;
	while ((max_num >> max_len) != 0)
		++max_len;
	i = -1;
	while (++i < max_len)
	{
		j = -1;
		count = head_a->count;
		while (++j < count)
		{
			if (((head_a->top->data.rank >> i) & 1) == 0)
				pb(head_a, head_b);
			else
				ra(head_a);
		}
		while (head_b->count != 0)
			pa(head_b, head_a);
	}
}

void	sorting_three(t_pointer head_a, t_pointer head_b)
{
	char	s[4];

	init_rank(head_a, head_b);
	get_rank(head_a);
	s[0] = head_a->top->data.rank + '0';
	s[1] = head_a->top->llink->data.rank + '0';
	s[2] = head_a->top->llink->llink->data.rank + '0';
	s[3] = 0;
	if (!ft_strncmp(s, "021", 3))
	{
		rra(head_a);
		sa(head_a);
	}
	else if (!ft_strncmp(s, "102", 3))
		sa(head_a);
	else if (!ft_strncmp(s, "120", 3))
		rra(head_a);
	else if (!ft_strncmp(s, "201", 3))
		ra(head_a);
	else if (!ft_strncmp(s, "210", 3))
	{
		sa(head_a);
		rra(head_a);
	}
}

void	sorting_four(t_pointer head_a, t_pointer head_b)
{
	get_rank(head_a);
	while (1)
	{
		if (head_a->top->data.rank == 0)
		{
			pb(head_a, head_b);
			break ;
		}
		else
			ra(head_a);
	}
	init_rank(head_a, head_b);
	sorting_three(head_a, head_b);
	pa(head_b, head_a);
}

void	sorting_five(t_pointer head_a, t_pointer head_b)
{
	static int	flag_0;
	static int	flag_1;

	while (!flag_0 || !flag_1)
	{
		if (head_a->top->data.rank == 0)
		{
			pb(head_a, head_b);
			flag_0 = 1;
		}
		else if (head_a->top->data.rank == 1)
		{
			pb(head_a, head_b);
			flag_1 = 1;
		}
		else
			ra(head_a);
	}
	if (head_b->top->data.rank < head_b->top->llink->data.rank)
		sb(head_b);
	init_rank(head_a, head_b);
	sorting_three(head_a, head_b);
	pa(head_b, head_a);
	pa(head_b, head_a);
}
