/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:19:07 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 16:15:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	find_first(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

size_t	find_last(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[ft_strlen(s1) - i - 1]) == 0)
			break ;
		i++;
	}
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*trim;

	if (s1 == NULL)
		return (NULL);
	if (ft_strncmp(s1, "", 1) == 0)
		return (ft_strdup(""));
	if (ft_strncmp(set, "", 1) == 0 || set == NULL)
		return (ft_strdup(s1));
	first = find_first(s1, set);
	last = find_last(s1, set);
	if (first >= last)
		return (ft_strdup(""));
	trim = malloc(sizeof(char) * (last - first + 1));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s1 + first, last - first + 1);
	return (trim);
}
