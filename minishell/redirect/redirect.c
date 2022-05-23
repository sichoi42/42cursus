/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:36:06 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:42:05 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static int	red_here_doc(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDWR);
	if (fd == -1)
	{
		print_error("minishell", file_name, strerror(errno), NULL);
		return (WRONG_ACTION);
	}
	unlink(file_name);
	return (dup_check(fd, STDIN_FILENO));
}

static int	red_in(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDWR);
	if (fd == -1)
		print_error("minishell", f_name, strerror(errno), NULL);
	else
	{
		dup_check(fd, STDIN_FILENO);
		close(fd);
		return (OK);
	}
	return (WRONG_ACTION);
}

static int	red_out(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		print_error("minishell", f_name, strerror(errno), NULL);
	else
	{
		dup_check(fd, STDOUT_FILENO);
		close(fd);
		return (OK);
	}
	return (WRONG_ACTION);
}

static int	red_append(char *f_name)
{
	int	fd;

	fd = open(f_name, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (fd == -1)
		print_error("minishell", f_name, strerror(errno), NULL);
	else
	{
		dup_check(fd, STDOUT_FILENO);
		close(fd);
		return (OK);
	}
	return (WRONG_ACTION);
}

int	red_open_file(t_token *t, char *f_name)
{
	if (t->token & T_RE_INPUT)
		return (red_in(f_name));
	else if (t->token & T_RE_APPEND_OUTPUT)
		return (red_append(f_name));
	else if (t->token & T_RE_OUTPUT)
		return (red_out(f_name));
	else if (t->token & T_RE_HEREDOC)
		return (red_here_doc(t->file_name));
	return (WRONG_ACTION);
}
