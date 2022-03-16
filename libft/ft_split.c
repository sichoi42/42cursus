/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:37:23 by sichoi            #+#    #+#             */
/*   Updated: 2022/02/24 16:12:48 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_row(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	while (s[i] == c)
		i++;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] == c)
		count--;
	return (++count);
}

char	**free_if_fail(char **split, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**put_split(char const *s, char c, int row, char **split)
{
	int	i;
	int	j;
	int	k;
	int	start;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	k = 0;
	while (k < row)
	{
		j = 0;
		start = i;
		while (s[i] != c && s[i++])
			j++;
		split[k] = malloc(sizeof(char) * j + 1);
		if (split[k] == NULL)
			return (free_if_fail(split, k));
		ft_strlcpy(split[k], &s[start], j + 1);
		while (s[i] == c && s[i])
			i++;
		k++;
	}
	split[k] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		row;

	if (s == NULL)
		return (NULL);
	if (ft_strncmp(s, "", 1) == 0)
		row = 0;
	else
		row = count_row(s, c);
	split = malloc(sizeof(char *) * (row + 1));
	if (split == NULL)
		return (NULL);
	split = put_split(s, c, row, split);
	return (split);
}
