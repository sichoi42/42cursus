/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:51:14 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/13 12:03:19 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_admin *admin)
{
	int	i;

	admin->fork = malloc(sizeof(pthread_mutex_t) * admin->n);
	if (admin->fork == 0)
		return (1);
	i = 0;
	while (i < admin->n)
	{
		if (pthread_mutex_init(&admin->fork[i], 0) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&admin->print, 0) != 0)
		return (1);
	if (pthread_mutex_init(&admin->check_eat, 0) != 0)
		return (1);
	return (0);
}

void	init_philo(t_admin *admin)
{
	int	i;

	i = 0;
	while (i < admin->n)
	{
		admin->philo[i].num = i;
		admin->philo[i].lfork = (i + 1) % admin->n;
		admin->philo[i].rfork = i;
		admin->philo[i].eat_cnt = 0;
		admin->philo[i].dead_line = admin->time_to_die;
		admin->philo[i].admin = admin;
		i++;
	}
}

int	init(t_admin *admin, int argc, char **argv)
{
	admin->n = ft_atoi(argv[1]);
	admin->time_to_die = ft_atoi(argv[2]);
	admin->time_to_eat = ft_atoi(argv[3]);
	admin->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		admin->at_least_eat = ft_atoi(argv[5]);
	else
		admin->at_least_eat = -1;
	admin->is_finished = 0;
	admin->philo = malloc(sizeof(t_philo) * admin->n);
	if (admin->philo == 0)
		return (1);
	init_philo(admin);
	if (init_mutex(admin))
		return (1);
	return (0);
}
