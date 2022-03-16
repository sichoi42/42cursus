/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:11:14 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/21 15:59:38 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	error_treat(char *s, t_pointer head)
{
	long long	value;

	value = ft_atoi(s);
	if (value > 2147483647 || value < -2147483648)
		return (-1);
	if (is_digit(s) == -1 || init_stack((int)value, head) == -1)
		return (-1);
	return (0);
}

int	treat_argv(int argc, char **argv, t_pointer head)
{
	char	**s;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		s = ft_split(argv[i], ' ');
		if (s == 0 || s[0] == 0)
			return (-1);
		j = 0;
		while (s[j])
		{
			if (error_treat(s[j], head) == -1)
				return (-1);
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_pointer	head_a;
	int			check;

	if (argc == 1)
		exit(1);
	head_a = malloc(sizeof(t_stack));
	if (head_a == 0)
		write_error();
	head_a->llink = NULL;
	head_a->rlink = NULL;
	if (treat_argv(argc, argv, head_a) == -1)
		write_error();
	check = is_sorted(head_a);
	if (check == 0)
		exit(1);
	else if (check == -2)
		write_error();
	if (sorting(head_a) == -1)
		write_error();
	head_a = free_stack(head_a);
	return (0);
}
