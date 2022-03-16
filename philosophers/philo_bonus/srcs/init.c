/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:51:14 by sichoi            #+#    #+#             */
/*   Updated: 2021/12/30 19:28:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_sem(t_admin *admin)
{
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/check_eat");
	sem_unlink("/over_eat");
	sem_unlink("/is_finished");
	admin->fork = sem_open("/fork", O_CREAT, S_IRWXU, admin->n);
	if (admin->fork == SEM_FAILED)
		return (1);
	admin->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	if (admin->print == SEM_FAILED)
		return (1);
	admin->check_eat = sem_open("/check_eat", O_CREAT, S_IRWXU, 1);
	if (admin->check_eat == SEM_FAILED)
		return (1);
	admin->over_eat = sem_open("/over_eat", O_CREAT, S_IRWXU, admin->n);
	if (admin->over_eat == SEM_FAILED)
		return (1);
	admin->is_finished = sem_open("/is_finished", O_CREAT, S_IRWXU, admin->n);
	if (admin->is_finished == SEM_FAILED)
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
		admin->philo[i].eat_cnt = 0;
		admin->philo[i].all_ate = 0;
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
	admin->philo = malloc(sizeof(t_philo) * admin->n);
	if (admin->philo == 0)
		return (1);
	init_philo(admin);
	if (init_sem(admin))
		return (1);
	return (0);
}
