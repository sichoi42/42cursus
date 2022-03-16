/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:36:56 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/13 16:55:29 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	send_msg(int pid, int bi)
{
	int	check;

	check = 0;
	if (bi == 0)
		check = kill(pid, SIGUSR1);
	else if (bi == 1)
		check = kill(pid, SIGUSR2);
	if (check < 0)
	{
		ft_putstr("Kill Error!");
		exit(1);
	}
	usleep(50);
}

void	binary_sending(int pid, int n)
{
	int	i;
	int	bi;

	i = 7;
	while (i >= 0)
	{
		bi = n >> i & 1;
		send_msg(pid, bi);
		i--;
	}
}

void	send_control(int pid, char *s)
{
	int				n;
	int				i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char *)s;
	ft_putstr("\n");
	while (buf[i])
	{
		n = (int)buf[i];
		binary_sending(pid, n);
		i++;
	}
	n = (int)buf[i];
	binary_sending(pid, n);
}

void	client_handler(int signo, siginfo_t *info, void *none)
{
	(void)signo;
	(void)info;
	(void)none;
	ft_putstr("Server checked signal!");
	exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	act.sa_sigaction = client_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &act, 0) < 0)
	{
		ft_putstr("Sigaction Error!\n");
		exit(1);
	}
	if (argc != 3)
	{
		ft_putstr("Usage : ./client [PID] [MSG]\n");
		exit(1);
	}
	else
	{
		ft_putstr("PID = ");
		ft_putstr(argv[1]);
		ft_putstr(", MSG = ");
		ft_putstr(argv[2]);
		send_control(ft_atoi(argv[1]), argv[2]);
	}
	while (1)
		;
	return (0);
}
