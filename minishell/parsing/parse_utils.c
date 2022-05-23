/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:59:06 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/18 19:10:09 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

// parsing tree의 새 노드를 생성하는 함수.
t_ast	*create_new_node(t_ast *root, enum e_tree_type tree_type)
{
	t_ast	*new;

	new = malloc(sizeof(t_ast));
	if (new == NULL)
		exit(1);
	new->left = NULL;
	new->right = NULL;
	new->root = root;
	new->token = NULL;
	new->tree_type = tree_type;
	new->argc = 0;
	return (new);
}

// parsing tree를 만들 때 token 메모리를 복제하는 함수.
t_token	*ft_token_dup(t_token *src)
{
	t_token	*dst;

	dst = malloc(sizeof(t_token));
	if (dst == NULL)
		return (NULL);
	dst->token = src->token;
	dst->type = src->type;
	dst->s = ft_strdup(src->s);
	dst->file_name = NULL;
	if (src->file_name != NULL)
		dst->file_name = ft_strdup(src->file_name);
	dst->next = NULL;
	return (dst);
}

// TREE_PIPE, TREE_BUNDLE, TREE_RE, TREE_CMD
char	*get_tree_type_str(enum e_tree_type tree_type)
{
	char	*s;

	s = NULL;
	if (tree_type == TREE_PIPE)
		s = "TREE_PIPE";
	else if (tree_type == TREE_BUNDLE)
		s = "TREE_BUNDLE";
	else if (tree_type == TREE_RE)
		s = "TREE_RE";
	else if (tree_type == TREE_CMD)
		s = "TREE_CMD";
	return (s);
}

// postorder로 tree를 free
void	free_tree(t_ast	*node)
{
	if (node)
	{
		free_tree(node->left);
		free_tree(node->right);
		free_token(node->token);
		free(node);
		node = NULL;
	}
}
