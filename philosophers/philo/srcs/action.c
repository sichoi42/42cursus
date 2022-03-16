/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:51:20 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/16 16:49:29 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_philo *philo)
{
	if (philo->num % 2)
	{
		pthread_mutex_lock(&philo->admin->fork[philo->lfork]);
		pthread_mutex_lock(&philo->admin->fork[philo->rfork]);
	}
	else
	{
		pthread_mutex_lock(&philo->admin->fork[philo->rfork]);
		pthread_mutex_lock(&philo->admin->fork[philo->lfork]);
	}
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->admin->check_eat);
	print_action(philo, "is eating");
	philo->dead_line = now(philo->admin) + philo->admin->time_to_die;
	pthread_mutex_unlock(&philo->admin->check_eat);
	msleep(philo->admin->time_to_eat, philo->admin);
	pthread_mutex_unlock(&philo->admin->fork[philo->lfork]);
	pthread_mutex_unlock(&philo->admin->fork[philo->rfork]);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n)
		i++;
	if (i == n)
		return ((int)str1[i - 1] - (int)str2[i - 1]);
	else
		return ((int)str1[i] - (int)str2[i]);
}

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&(philo->admin->print));
	if (!(philo->admin->is_finished))
		printf("%d %d %s\n", now(philo->admin), philo->num + 1, action);
	if (ft_strncmp(action, "died", 4) != 0)
		pthread_mutex_unlock(&(philo->admin->print));
}
