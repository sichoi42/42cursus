/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:27:36 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:27:38 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_half(int fd, char *buf, int *flag)
{
	pass_space(fd, buf, "");
	if (*buf == '2')
		*flag = 1;
	else
		*flag = 0;
}

void	check_texture(int fd, char *buf, int *texture)
{
	pass_space(fd, buf, " \t");
	if (*buf == '0')
		*texture = 0;
	else if (*buf == '1')
		*texture = 1;
	else
		print_error("Wrong input: not texture\n");
}
