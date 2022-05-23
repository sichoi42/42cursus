/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:15:25 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/19 22:21:13 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minishell.h"

void	free_token(t_token *t)
{
	t_token	*p;
	t_token	*tmp;

	if (t)
	{
		p = t->next;
		while (p)
		{
			tmp = p->next;
			free(p->s);
			if (p->file_name)
				free(p->file_name);
			free(p);
			p = tmp;
		}
		if (t->s)
			free(t->s);
		if (t->file_name)
			free(t->file_name);
		free(t);
	}
}

// 두 문자열을 완전히 합쳐 새로운 문자열을 만들기 원할 때 사용하는 함수이므로
// s1과 s2를 모두 free.
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		n;

	if (s1 == NULL && s2 != NULL)
		return (s2);
	if (s1 != NULL && s2 == NULL)
		return (s1);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		exit(1);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	n = i;
	i = 0;
	while (s2[i])
	{
		str[n + i] = s2[i];
		++i;
	}
	str[n + i] = 0;
	free(s1);
	free(s2);
	return (str);
}

// s1과 s2의 최대 n개를 연결하여 반환하는 함수.(메모리 복제가 발생하고, s1은 free하지만 s2는 free하지 않음.)
// 이 함수는 line에서 값을 dup해오기 위해서 사용되므로 원래 line을 free하지 않도록 하기 위함.
char	*ft_strnjoin(char *s1, char *s2, int len)
{
	char	*str;
	int		i;
	int		n;

	if (len < 0)
		len = ft_strlen(s2);
	if (s1 == NULL && s2 != NULL)
		return (ft_strndup(s2, len));
	if (s1 != NULL && s2 == NULL)
		return (s1);
	str = malloc(ft_strlen(s1) + len + 1);
	if (str == NULL)
		exit(1);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	n = i;
	i = -1;
	while (s2[++i] && i < len)
		str[n + i] = s2[i];
	str[n + i] = 0;
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (NULL);
}

t_token	*create_new_token(void)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		exit(1);
	new->next = NULL;
	new->file_name = NULL;
	new->token = T_INIT;
	return (new);
}
