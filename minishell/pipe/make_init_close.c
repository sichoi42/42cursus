/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_init_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:30:53 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:46:10 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void	init_pipe(int *pipe_fd)
{
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
}

void	close_pipe(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

int	make_pipe(int *p_fd)
{
	int	rtn;

	rtn = pipe(p_fd);
	if (rtn == -1)
	{
		print_error("minishell", strerror(errno), NULL, NULL);
		exit(1);
	}
	dup_check(p_fd[1], STDOUT_FILENO);
	return (0);
}
