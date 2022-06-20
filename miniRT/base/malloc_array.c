/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:19 by swi               #+#    #+#             */
/*   Updated: 2022/06/17 16:57:20 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>

void	*malloc_array(int size, int len)
{
	void	*temp;

	temp = malloc(size * len);
	if (temp == NULL)
		print_error(NULL);
	return (temp);
}
