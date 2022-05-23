/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_etc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:00:01 by swi               #+#    #+#             */
/*   Updated: 2022/05/21 17:52:21 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <stdlib.h>

void	count_words_alloc(char ***paths, char *org, char div[], int *count)
{
	int		i;
	int		w;

	w = 0;
	while (*org != '\0')
	{
		i = 0;
		while (div[i] != '\0')
		{
			if (*org == div[i++])
			{
				w = 0;
				break ;
			}
		}
		if (div[i] == '\0')
		{
			if (w == 0)
				++(*count);
			++w;
		}
		++org;
	}
	*paths = malloc_array(sizeof(char *), *count + 1);
}

void	count_word_alloc(char *org, char **words, char *div, int *max_len)
{
	int		i;
	int		len;

	len = 1;
	*max_len = 0;
	while (1)
	{
		i = -1;
		while (div[++i] != '\0')
			if (*org == div[i])
				break ;
		if (div[i] == '\0' && *org != '\0')
			++len;
		else
		{
			if (len != 1)
				*(words++) = malloc_array(sizeof(char), len);
			*max_len = ft_max(*max_len, len);
			len = 1;
		}
		if (*org++ == '\0')
			break ;
	}
	*words = NULL;
}

void	fill_array(char *org, char **words, char *div, int count)
{
	int		i;
	int		j;
	int		w;

	j = 0;
	w = 0;
	while (*org != '\0')
	{
		i = -1;
		while (div[++i] != '\0')
			if (*org == div[i])
				break ;
		if (div[i] == '\0')
			words[j][w++] = *org;
		else if (w != 0)
		{
			if (count - 1 == j)
				break ;
			words[j++][w] = '\0';
			w = 0;
		}
		++org;
	}
	words[j][w] = '\0';
}

void	find_path(char ***paths, int *max_path, t_envs *e)
{
	char	*path;
	int		count;

	path = get_env_value(e, "PATH");
	count = 0;
	if (path == NULL)
	{
		*max_path = 1;
		*paths = malloc(sizeof(char *));
		(*paths)[0] = NULL;
		return ;
	}
	count_words_alloc(paths, path, ":", &count);
	count_word_alloc(path, *paths, ":", max_path);
	fill_array(path, *paths, ":", count);
}
