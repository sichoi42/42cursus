/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:51:06 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/16 16:42:29 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitoring(void *param)
{
	t_philo		*philo;
	t_admin		*admin;
	int			i;

	philo = (t_philo *)param;
	admin = philo->admin;
	while (1)
	{
		sem_wait(admin->check_eat);
		if (now(admin) > philo->dead_line)
		{
			sem_wait(philo->admin->print);
			printf("%d %d %s\n", now(philo->admin), philo->num + 1, "died");
			sem_post(admin->is_finished);
			i = -1;
			while (++i < admin->n)
				sem_post(admin->over_eat);
			exit(0);
		}
		sem_post(admin->check_eat);
		check_all_ate(philo, admin);
		usleep(100);
	}
	return (NULL);
}

void	simulation(t_philo *philo)
{
	pthread_t	administrator;
	t_admin		*admin;

	admin = philo->admin;
	sem_wait(admin->over_eat);
	sem_wait(admin->is_finished);
	philo->dead_line = admin->time_to_die;
	if (pthread_create(&administrator, 0, monitoring, philo) != 0)
		exit(1);
	while (1)
	{
		eating(philo, admin);
		philo->eat_cnt++;
		print_action(philo, "is sleeping");
		msleep(admin->time_to_sleep, admin);
		print_action(philo, "is thinking");
		usleep(100);
	}
	pthread_join(administrator, 0);
}

int	start_simulation(t_admin *admin)
{
	int			i;

	admin->start = get_mtime_of_day();
	i = 0;
	while (i < admin->n)
	{
		admin->philo[i].pid = fork();
		if (admin->philo[i].pid < 0)
			return (1);
		if (admin->philo[i].pid == 0)
			simulation(&admin->philo[i]);
		i++;
		usleep(5);
	}
	msleep(5 * admin->n, admin);
	return (0);
}

void	kill_philo(t_admin *admin)
{
	int	i;
	int	status;

	if (admin->at_least_eat >= 0)
	{
		sem_wait(admin->is_finished);
		i = -1;
		while (++i < admin->n)
			sem_wait(admin->over_eat);
	}
	else
		waitpid(-1, &status, 0);
	i = -1;
	while (++i < admin->n)
		kill(admin->philo[i].pid, SIGTERM);
}

int	main(int argc, char **argv)
{
	t_admin	admin;

	if (argc < 5 || argc > 6)
	{
		printf("Error! use ./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep [at east eat]\n");
		return (1);
	}
	else
	{
		if (init(&admin, argc, argv) == 1)
			return (1);
		start_simulation(&admin);
		kill_philo(&admin);
		free_resource(&admin);
	}
	return (0);
}
