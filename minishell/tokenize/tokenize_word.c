/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:01:10 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/12 18:15:18 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

// 현재 end 문자가 일반 문자열인 경우, 일반 문자열 사이 offset을 구하여 그 길이만큼 dup시킨 후, s에 join.
void	join_normal_word(char **s, char **start, char **end)
{
	if (**end && !ft_strchr("\"\'$", **end))
	{
		while (**end && !is_space(**end) && !ft_strchr("\"\'$|><", **end))
			++(*end);
		*s = ft_strnjoin(*s, *start, *end - *start);
		*start = *end;
	}
}

// quote를 만났을 때 quote의 끝 점 위치로 end를 이동, 닫히지 않은 quote라면 end는 null로 향하게 됨.
void	move_quote_end(char **start, char **end)
{
	++(*end);
	while (**end)
	{
		if (**end == **start)
			break ;
		++(*end);
	}
}

// 닫히지 않은 quote인 경우 free후 token에 null을 반환.
t_token	*treat_unclosed_quote(t_token **new, char **s)
{
	free(*s);
	free(*new);
	return (NULL);
}

// word token에, 해당하는 정보를 입력.
void	fill_word_info(t_token **new, char *s, enum e_token *token)
{
	if (s == NULL)
		s = ft_strdup("");
	(*new)->s = s;
	*token |= T_WORD;
	(*new)->type = ARGS;
	(*new)->token = *token;
}

// 다음 토큰(|><)이나 space를 만나기 전까지 loop를 돌면서 word부분을 tokenize하는 함수.
// word에 포함될 수 있는 것은 1. $로 시작하는 문자열, 2. quote로 둘러쌓인 문자열, 3. 일반 문자열
// 반복문을 돌면서 s에 계속해서 1, 2, 3을 join하여 word 토큰화를 진행.
t_token	*tokenize_word(char **start, char **end, enum e_token *token, t_envs *e)
{
	t_token	*new;
	char	*s;

	new = create_new_token();
	s = NULL;
	while (**end && !is_space(**end) && !ft_strchr("|><", **end))
	{
		join_normal_word(&s, start, end);
		if (**end && ft_strchr("\"\'", **end))
		{
			move_quote_end(start, end);
			if (**end == 0)
				return (treat_unclosed_quote(&new, &s));
			else
				s = ft_strjoin(s, quote_in_word(start, end, token, e));
		}
		if (**end && **end == '$')
			s = ft_strjoin(s, dollar_in_word(start, end, token, e));
	}
	fill_word_info(&new, s, token);
	if (**end == 0)
		*start = *end;
	else
		*start = *end + 1;
	return (new);
}
