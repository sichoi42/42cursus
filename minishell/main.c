/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:16:18 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/21 01:08:56 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_envs	e;

	if (argc > 1)
		return (1);
	(void)argv;
	input_env(&e, envp);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	loop(&e);
	return (0);
}
