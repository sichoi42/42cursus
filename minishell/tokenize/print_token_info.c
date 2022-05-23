/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:12:39 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/19 22:20:48 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../minishell.h"

// token 정보를 문자열로 출력.
void	print_token_str(enum e_token token)
{
	if (token & T_WORD)
		printf("%s, ", "T_WORD");
	if (token & T_PIPE)
		printf("%s, ", "T_PIPE");
	if (token & T_STAR)
		printf("%s, ", "T_STAR");
	if (token & T_RE_INPUT)
		printf("%s, ", "T_RE_INPUT");
	if (token & T_RE_OUTPUT)
		printf("%s, ", "T_RE_OUTPUT");
	if (token & T_RE_HEREDOC)
		printf("%s, ", "T_RE_HEREDOC");
	if (token & T_RE_APPEND_OUTPUT)
		printf("%s, ", "T_RE_APPEND_OUTPUT");
	if (token & T_EXIT_CODE)
		printf("%s, ", "T_EXIT_CODE");
	printf("\n");
}

// token type을 문자열로 출력.
void	print_type_str(enum e_type type)
{
	if (type & ARGS)
		printf("%s, ", "ARGS");
	if (type & PIPE)
		printf("%s, ", "PIPE");
	if (type & REDIRECT)
		printf("%s, ", "REDIRECT");
	if (type & STAR)
		printf("%s, ", "STAR");
	printf("\n");
}

// token Linked list에서 하나씩 token 정보를 출력.
void	print_token_list(t_token *t)
{
	t_token	*p;

	if (t)
	{
		p = t->next;
		while (p)
		{
			printf("%s\n", p->s);
			print_token_str(p->token);
			print_type_str(p->type);
			printf("-----------------\n");
			p = p->next;
		}
	}
}
