/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:21:41 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 18:56:05 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <unistd.h>

void	next_line(int fd, char *buf)
{
	int	size;

	size = ft_read(fd, buf, 1);
	while (size == 1)
	{
		write(STDOUT_FILENO, buf, 1);
		if (*buf != '\n')
		{
			if (*buf == '\0')
				break ;
			size = ft_read(fd, buf, 1);
			continue ;
		}
		else
			break ;
	}
	if (size == 0)
		*buf = '\0';
}
