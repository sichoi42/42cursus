/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:51:20 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/13 12:36:01 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_philo *philo, t_admin *admin)
{
	sem_wait(admin->fork);
	sem_wait(admin->fork);
	print_action(philo, "has taken a fork");
	sem_wait(admin->check_eat);
	print_action(philo, "is eating");
	philo->dead_line = now(admin) + admin->time_to_die;
	sem_post(admin->check_eat);
	msleep(admin->time_to_eat, admin);
	sem_post(admin->fork);
	sem_post(admin->fork);
}

void	print_action(t_philo *philo, char *action)
{
	sem_wait(philo->admin->print);
	printf("%d %d %s\n", now(philo->admin), philo->num + 1, action);
	sem_post(philo->admin->print);
}
