/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:55:14 by sichoi            #+#    #+#             */
/*   Updated: 2022/01/13 12:36:09 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	struct s_admin	*admin;
	pid_t			pid;
	int				num;
	int				dead_line;
	int				eat_cnt;
	int				all_ate;
}	t_philo;

typedef struct s_admin
{
	int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				at_least_eat;
	long			start;
	t_philo			*philo;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*check_eat;
	sem_t			*over_eat;
	sem_t			*is_finished;
}	t_admin;

/*******utils.c*********/
void	msleep(int milli, t_admin *admin);
long	get_mtime_of_day(void);
int		now(t_admin *admin);
int		ft_atoi(char *s);
void	free_resource(t_admin *admin);

/******init.c**********/
int		init(t_admin *admin, int argc, char **argv);
void	init_philo(t_admin *admin);
int		init_sem(t_admin *admin);

/******action.c********/
void	eating(t_philo *philo, t_admin *admin);
void	print_action(t_philo *philo, char *action);

/*****surplus.c*******/
void	check_all_ate(t_philo *philo, t_admin *admin);

#endif
