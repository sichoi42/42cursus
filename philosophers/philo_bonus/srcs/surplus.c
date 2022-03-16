/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:36:23 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/13 12:40:58 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_all_ate(t_philo *philo, t_admin *admin)
{
	if (admin->at_least_eat >= 0)
	{
		if (philo->all_ate == 0 && philo->eat_cnt >= admin->at_least_eat)
		{
			sem_post(admin->is_finished);
			sem_post(admin->over_eat);
			philo->all_ate = 1;
		}
	}
}
