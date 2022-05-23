/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:14:48 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:14:49 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void	*malloc_array(int size, int len)
{
	void	*temp;

	temp = malloc(size * len);
	if (temp == NULL)
	{
		print_error("minishell", strerror(errno), NULL, NULL);
		exit(1);
	}
	return (temp);
}
