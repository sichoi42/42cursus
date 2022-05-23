/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:14:42 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:14:43 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>

void	print_error(char *a, char *b, char *c, char *d)
{
	write(2, a, ft_strlen(a));
	if (b != NULL)
	{
		write(2, ": ", 2);
		write(2, b, ft_strlen(b));
		if (c != NULL)
		{
			write(2, ": ", 2);
			write(2, c, ft_strlen(c));
			if (d != NULL)
			{
				write(2, ": ", 2);
				write(2, d, ft_strlen(d));
			}
		}
	}
	write(2, "\n", 1);
}
