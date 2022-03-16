/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:07:00 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 16:01:34 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_pointer head_b, t_pointer head_a)
{
	t_data	data;

	data = pop(head_b);
	if (push_stack(data, head_a) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_pointer head_a, t_pointer head_b)
{
	t_data	data;

	data = pop(head_a);
	if (push_stack(data, head_b) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
