/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:03:00 by sichoi            #+#    #+#             */
/*   Updated: 2022/05/18 22:16:29 by swi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stddef.h>

int	syntax_pipe(t_ast *node, t_token *t, t_ast *root)
{
	int	i;

	i = -1;
	while (++i < root->pipe_cnt - 1)
		node = node->right;
	if (t->type & PIPE)
	{
		if (node->root->pipe_cnt == -1)
			node->root->pipe_cnt = 2;
		else
			++(node->root->pipe_cnt);
		node->right = create_new_node(root, TREE_PIPE);
		node->right->token = ft_token_dup(t);
	}
	else
	{
		if (node->left == NULL)
			node->left = create_new_node(root, TREE_BUNDLE);
		if (syntax_bundle(node->left, t, root) == -1)
			return (-1);
	}
	return (0);
}

int	syntax_bundle(t_ast *node, t_token *t, t_ast *root)
{
	if (t->type & ARGS || t->type & STAR)
	{
		if (node->right == NULL)
			node->right = create_new_node(root, TREE_CMD);
		syntax_cmd(node->right, t, root);
	}
	else if (t->type & REDIRECT)
	{
		if (node->left == NULL)
			node->left = create_new_node(root, TREE_RE);
		syntax_redirect(node->left, t, root);
	}
	return (0);
}

int	syntax_redirect(t_ast *node, t_token *t, t_ast *root)
{
	if (node->left == NULL)
	{
		node->left = create_new_node(root, TREE_RE);
		syntax_decision_redirect(node->left, t, root);
	}
	else
	{
		if (t->type & REDIRECT)
		{
			if (node->right == NULL)
				node->right = create_new_node(root, TREE_RE);
			if (syntax_redirect(node->right, t, root) == -1)
				return (-1);
		}
	}
	return (0);
}

void	syntax_decision_redirect(t_ast *node, t_token *t, t_ast *root)
{
	(void)root;
	node->token = ft_token_dup(t);
}

int	syntax_cmd(t_ast *node, t_token *t, t_ast *root)
{
	t_token	*p;

	(void)root;
	if (node->token == NULL)
	{
		node->token = ft_token_dup(t);
		node->argc = 1;
	}
	else
	{
		p = node->token;
		while (p->next)
			p = p->next;
		p->next = ft_token_dup(t);
		++(node->argc);
	}
	return (0);
}
