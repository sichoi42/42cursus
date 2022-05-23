/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:52:35 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/21 00:51:26 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <stdlib.h>

void	init_token_header(t_token **token_header)
{
	*token_header = malloc(sizeof(t_token));
	if (*token_header == NULL)
		exit(1);
	(*token_header)->s = NULL;
	(*token_header)->file_name = NULL;
	(*token_header)->next = NULL;
}

void	init_tree(t_ast **tree)
{
	*tree = malloc(sizeof(t_ast));
	if (tree == NULL)
		exit(1);
	(*tree)->token = NULL;
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->tree_type = TREE_PIPE;
	(*tree)->pipe_cnt = -1;
	(*tree)->root = *tree;
	(*tree)->std_fd[0] = dup(STDIN_FILENO);
	(*tree)->std_fd[1] = dup(STDOUT_FILENO);
}
