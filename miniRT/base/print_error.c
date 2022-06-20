/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:11 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:57:12 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	print_error(char *message)
{
	write(2, "Error\n", 6);
	if (message == NULL)
		perror(NULL);
	else
		write(2, message, ft_strlen(message));
	exit(1);
}
