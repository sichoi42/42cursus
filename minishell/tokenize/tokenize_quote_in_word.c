/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_quote_in_word.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:59:12 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/12 18:02:23 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stddef.h>

// start가 quote를 만날 때까지 loop를 돌면서 한글자씩 s에 join을 하되, $를 만나면 해당 부분을 해석하여 join함.
char	*quote_in_word(char **start, char **end, enum e_token *token, t_envs *e)
{
	char	*s;
	char	*value;
	char	quote;

	s = NULL;
	quote = **start;
	++(*start);
	while (**start != **end)
	{
		if (**start == '$' && quote == '\"')
		{
			value = dollar_in_quote(start, end, token, e);
			s = ft_strjoin(s, value);
		}
		else
			s = ft_strnjoin(s, *start, 1);
		++(*start);
	}
	if (s == NULL)
		s = ft_strdup("");
	++(*end);
	*start = *end;
	return (s);
}
