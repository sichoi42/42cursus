/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:51:06 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/15 15:39:24 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_all_ate(t_admin *admin)
{
	int	i;
	int	flag;

	if (admin->at_least_eat >= 0)
	{
		while (!admin->is_finished)
		{
			i = -1;
			flag = 1;
			while (++i < admin->n)
			{
				if (admin->philo[i].eat_cnt < admin->at_least_eat)
				{
					flag = 0;
					break ;
				}
			}
			if (flag)
				admin->is_finished = 1;
		}
	}
	else
		while (!admin->is_finished)
			;
}

void	*monitoring(void *param)
{
	t_philo	*philo;
	t_admin	*admin;

	philo = (t_philo *)param;
	admin = philo->admin;
	while (!admin->is_finished)
	{
		pthread_mutex_lock(&admin->check_eat);
		if (now(admin) > philo->dead_line)
		{
			print_action(philo, "died");
			admin->is_finished = 1;
		}
		pthread_mutex_unlock(&admin->check_eat);
		usleep(100);
	}
	return (NULL);
}

void	*simulation(void *param)
{
	t_philo		*philo;
	t_admin		*admin;
	pthread_t	administrator;

	philo = (t_philo *)param;
	admin = philo->admin;
	if (philo->num % 2 || philo->num + 1 == admin->n)
		msleep(admin->time_to_eat, admin);
	if (pthread_create(&administrator, 0, monitoring, philo) != 0)
	{
		admin->is_finished = 1;
		return (NULL);
	}
	while (!admin->is_finished)
	{
		eating(philo);
		philo->eat_cnt++;
		print_action(philo, "is sleeping");
		msleep(admin->time_to_sleep, admin);
		print_action(philo, "is thinking");
		usleep(100);
	}
	pthread_detach(administrator);
	return (NULL);
}

int	start_simulation(t_admin *admin)
{
	int			i;

	admin->start = get_mtime_of_day();
	i = 0;
	while (i < admin->n)
	{
		if (pthread_create(&admin->philo[i].thread, 0,
				simulation, &admin->philo[i]) != 0)
			return (1);
		i++;
		usleep(10);
	}
	check_all_ate(admin);
	i = 0;
	while (i < admin->n)
	{
		pthread_detach(admin->philo[i].thread);
		i++;
	}
	return (0);
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
		if (start_simulation(&admin) == 1)
			return (1);
		if (free_resource(&admin) == 1)
			return (1);
	}
	return (0);
}
