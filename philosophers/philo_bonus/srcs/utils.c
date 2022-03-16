/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:33:27 by sichoi            #+#    #+#             */
/*   Updated: 2021/12/30 19:28:48 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	msleep(int milli, t_admin *admin)
{
	long	target;

	target = now(admin);
	while (1)
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

void	free_resource(t_admin *admin)
{
	sem_close(admin->fork);
	sem_close(admin->print);
	sem_close(admin->check_eat);
	sem_close(admin->over_eat);
	sem_close(admin->is_finished);
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/check_eat");
	sem_unlink("/over_eat");
	sem_unlink("/is_finished");
	free(admin->philo);
}
