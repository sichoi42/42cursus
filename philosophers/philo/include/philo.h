/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:55:14 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/13 12:00:08 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	struct s_admin	*admin;
	int				num;
	int				lfork;
	int				rfork;
	int				dead_line;
	int				eat_cnt;
	pthread_t		thread;
}	t_philo;

typedef struct s_admin
{
	int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				at_least_eat;
	int				is_finished;
	long			start;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	check_eat;
}	t_admin;

/*******utils.c*********/
void	msleep(int milli, t_admin *admin);
long	get_mtime_of_day(void);
int		now(t_admin *admin);
int		ft_atoi(char *s);
int		free_resource(t_admin *admin);

/******init.c**********/
int		init(t_admin *admin, int argc, char **argv);
void	init_philo(t_admin *admin);
int		init_mutex(t_admin *admin);

/******action.c********/
void	eating(t_philo *philo);
void	print_action(t_philo *philo, char *action);

#endif
