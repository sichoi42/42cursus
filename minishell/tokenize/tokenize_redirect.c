/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:55:05 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/12 18:18:13 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_redirect_token(char **start, char **end, enum e_token *token)
{
	if (*(*end + 1) && *(*end + 1) == **end)
	{
		if (**end == '>')
			*token |= T_RE_APPEND_OUTPUT;
		else
			*token |= T_RE_HEREDOC;
		++(*end);
	}
	else
	{
		if (**end == '>')
			*token |= T_RE_OUTPUT;
		else
			*token |= T_RE_INPUT;
	}
	++(*end);
	*start = *end;
}

// redirection을 만나면 대상 파일이 될 token을 tokenize.
t_token	*tokenize_redirect(char **start, char **end, enum e_token *t, t_envs *e)
{
	t_token	*new;

	get_redirect_token(start, end, t);
	moving_two_pointers(start, end);
	if (ft_strchr("|", **start))
		new = tokenize_pipe(end, t);
	else if (ft_strchr("*", **start))
		new = tokenize_star(end, t);
	else
		new = tokenize_word(start, end, t, e);
	new->type |= REDIRECT;
	new->type &= ~ARGS;
	return (new);
}
