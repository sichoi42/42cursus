/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swi <swi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:14:38 by swi               #+#    #+#             */
/*   Updated: 2022/05/20 21:14:39 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tolower(char **str)
{
	int	i;
	int	diff;

	i = -1;
	diff = 'a' - 'A';
	while ((*str)[++i] != '\0')
	{
		if ((*str)[i] >= 'A' && (*str)[i] <= 'Z')
			(*str)[i] += diff;
	}
}