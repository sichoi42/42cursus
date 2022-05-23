/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_one_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:55:56 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/12 18:02:22 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

t_token	*tokenize_pipe(char **end, enum e_token *token)
{
	t_token		*new;

	new = create_new_token();
	new->s = ft_strndup(*end, 1);
	if (new->s == NULL)
		exit(1);
	*token |= T_PIPE;
	new->type = PIPE;
	new->token = *token;
	++(*end);
	return (new);
}

t_token	*tokenize_star(char **end, enum e_token *token)
{
	t_token		*new;

	new = create_new_token();
	new->s = ft_strndup(*end, 1);
	if (new->s == NULL)
		exit(1);
	*token |= T_STAR;
	new->type = STAR;
	new->token = *token;
	++(*end);
	return (new);
}
