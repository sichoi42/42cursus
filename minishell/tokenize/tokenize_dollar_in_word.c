/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_dollar_in_word.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:57:57 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/19 17:09:26 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

// key를 넣으면 value를 dup하여 반환.
char	*key_to_value(char **start, char *end, t_envs *e)
{
	char	*key;
	char	*value;

	key = ft_strndup(*start, end - *start);
	value = ft_strdup(get_env_value(e, key));
	free(key);
	return (value);
}

// word에서 만나는 dollar를 처리하는 함수.
// $다음이 다른 토큰(pipe, redirect)이면 $를 문자 그대로 해석.
// $다음이 ?이면 EXIT_CODE처리를 위한 토큰을 추가.
// $다음이 일반문자면 해당 환경변수의 value를 가져옴.
char	*dollar_in_word(char **start, char **end, enum e_token *t, t_envs *e)
{
	char	*s;

	++(*end);
	if (**end == 0 || is_space(**end) || ft_strchr("\"\'|><$/", **end))
	{
		if (ft_strchr("\"\'", **end))
			s = ft_strdup("");
		else
			s = ft_strdup("$");
	}
	else if (**end == '?')
	{
		s = ft_itoa(g_exit_code);
		*t |= T_EXIT_CODE;
		++(*end);
	}
	else
	{
		while (**end && !is_space(**end) && !ft_strchr("\"\'|><$/", **end))
			++(*end);
		++(*start);
		s = key_to_value(start, *end, e);
	}
	*start = *end;
	return (s);
}

// quote안에서 만나는 dollar를 처리하는 함수.
// $다음이 다른 토큰(pipe, redirect)이면 $를 문자 그대로 해석.
// $다음이 ?이면 EXIT_CODE처리를 위한 토큰을 추가.
// $다음이 일반문자면 해당 환경변수의 value를 가져옴.
char	*dollar_in_quote(char **start, char **end, enum e_token *t, t_envs *e)
{
	char	*d_end;
	char	*s;

	d_end = *start + 1;
	if (*d_end == '?')
	{
		s = ft_itoa(g_exit_code);
		*t |= T_EXIT_CODE;
		++d_end;
	}
	else if (is_space(*d_end) || ft_strchr("\"\'|><$/", *d_end))
	{
		if (ft_strchr("\"\'", **end))
			s = ft_strdup("");
		s = ft_strdup("$");
	}
	else
	{
		while (*d_end && !is_space(*d_end) && !ft_strchr("\"\'|><$/", *d_end))
			++d_end;
		++(*start);
		s = key_to_value(start, d_end, e);
	}
	*start = d_end - 1;
	return (s);
}
