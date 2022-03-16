/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:33:27 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/12 21:53:18 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	msleep(int milli, t_admin *admin)
{
	long	target;

	target = now(admin);
	while (!admin->is_finished)
	{
		if (now(admin) - target >= milli)
			break ;
		usleep(50);
	}
}

long	get_mtime_of_day(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	now(t_admin *admin)
{
	return ((int)(get_mtime_of_day() - admin->start));
}

int	ft_atoi(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += s[i] - '0';
		i++;
	}
	return (n);
}

int	free_resource(t_admin *admin)
{
	int	i;

	i = 0;
	while (i < admin->n)
	{
		if (pthread_mutex_unlock(&admin->fork[i]) != 0)
			return (1);
		if (pthread_mutex_destroy(&admin->fork[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_unlock(&admin->print) != 0)
		return (1);
	if (pthread_mutex_destroy(&admin->print) != 0)
		return (1);
	if (pthread_mutex_unlock(&admin->check_eat) != 0)
		return (1);
	if (pthread_mutex_destroy(&admin->check_eat) != 0)
		return (1);
	free(admin->fork);
	free(admin->philo);
	return (0);
}
