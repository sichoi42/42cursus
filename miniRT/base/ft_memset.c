/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:56:45 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:56:49 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_memset(void *target, unsigned int size, int input)
{
	char				*cp_target;
	unsigned int		i;
	unsigned char		input_c;

	cp_target = (char *)target;
	i = -1;
	input_c = (unsigned char)input;
	while (++i < size)
		cp_target[i] = input_c;
}
