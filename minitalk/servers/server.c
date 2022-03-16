/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:36:51 by sichoi            #+#    #+#             */
/*   Updated: 2021/08/13 16:36:05 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	conv_and_print(int *s, siginfo_t *info)
{
	int			i;
	int			decimal;
	int			position;

	i = 8;
	decimal = 0;
	position = 0;
	while (--i >= 0)
	{
		if (s[i] == 1)
			decimal += 1 << position;
		position++;
	}
	if (decimal == 0)
	{
		ft_putstr("\n");
		if (kill(info->si_pid, SIGUSR2) == -1)
		{
			ft_putstr("Kill Error!\n");
			exit(1);
		}
	}
	else
		write(1, &decimal, 1);
}

void	handler(int signo, siginfo_t *info, void *none)
{
	static int	s[8];
	static int	i;

	(void)none;
	if (signo == SIGUSR1)
		s[i] = 0;
	else if (signo == SIGUSR2)
		s[i] = 1;
	i++;
	if (i == 8)
	{
		conv_and_print(s, info);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	char				*s;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, 0) < 0
		|| sigaction(SIGUSR2, &act, 0) < 0)
	{
		ft_putstr("Sigaction Error!\n");
		exit(1);
	}
	s = ft_itoa(getpid());
	if (s == 0)
	{
		ft_putstr("Malloc Error!\n");
		exit(1);
	}
	ft_putstr(s);
	ft_putstr("\n");
	free(s);
	while (1)
		;
	return (0);
}
