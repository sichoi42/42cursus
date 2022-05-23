/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:34:55 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:45:50 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int	dup_check(int fd_l, int fd_r)
{
	int	rtn;

	rtn = dup2(fd_l, fd_r);
	if (rtn == -1)
	{
		print_error("minishell", strerror(errno), NULL, NULL);
		exit(1);
	}
	return (OK);
}
