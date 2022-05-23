/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:53:20 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/21 00:38:26 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void	wait_child(int pid)
{
	int	status;
	int	ret;

	status = -1;
	if (waitpid(pid, &status, 0) >= 0)
	{
		if ((status & 0177) == 0)
			ret = (status >> 8) & 0x000000ff;
		else
		{
			ret = status & 0177;
			if (ret == SIGQUIT)
				print_error("Quit", "3", NULL, NULL);
			ret = 128 + ret;
		}
	}
	if (status != -1)
		g_exit_code = ret;
	while (waitpid(-1, &status, 0) >= 0)
		;
}

void	eof_exit(int col, int row)
{
	move_cursor(col + 11, row);
	printf("exit\n");
	close(STDOUT_FILENO);
}
