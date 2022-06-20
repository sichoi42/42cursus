/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:58:13 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:58:25 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <unistd.h>

int	ft_read(int fd, char *buf, int size)
{
	int	read_size;

	read_size = read(fd, buf, size);
	if (read_size == -1)
		print_error(NULL);
	return (read_size);
}
