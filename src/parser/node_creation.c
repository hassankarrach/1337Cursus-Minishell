/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbasri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:10:39 by aelbasri          #+#    #+#             */
/*   Updated: 2024/05/06 15:10:41 by aelbasri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_redir	*new_redir(t_token **head, int type)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->type = type;
	redir->hc_sep = NULL;
	redir->child = NULL;
	redir->file_name = (*head)->next->value;
	(*head) = (*head)->next->next;
	return (redir);
}

void	new_cmd(t_token **head, t_tree **root)
{
	int		i;
	t_data	data;

	data.args = NULL;
	data.redir = NULL;
	data.hold = NULL;
	data.cmd = NULL;
	i = 0;
	while ((*head) != NULL && (*head)->type != TOKEN_AND && \
	(*head)->type != TOKEN_OR && (*head)->type != TOKEN_PIPE && \
	(*head)->type != TOKEN_CLOSING_PARENTHESES)
	{
		if (redir_node(&data.args, &data.hold, head, &data.redir) == 1)
			continue ;
		if (g_lobal_minishell.hc == 1)
			return ;
		(*head) = (*head)->next;
		i++;
	}
	if (data.args != NULL)
		data.cmd = _cmd(data.args, TOKEN_WORD, i);
	data.hold2 = data.hold;
	if (data.hold != NULL)
		linking(&data.hold, data.cmd, &data.hold2, root);
	else
		nodes_link((t_tree *)data.cmd, root);
}

void	new_block(t_tree **root, t_tree *node, t_token **head)
{
	t_block	*block;

	while (*head != NULL && (*head)->type != TOKEN_CLOSING_PARENTHESES)
		(*head) = (*head)->next;
	block = malloc(sizeof(t_block));
	block->child = node;
	block->type = TOKEN_BLOCK;
	nodes_link((t_tree *)block, root);
}

void	new_pipe(t_tree **root)
{
	t_pipe	*n_pipe;

	g_lobal_minishell.pipes_nbr++;
	n_pipe = malloc(sizeof(t_pipe));
	n_pipe->type = TOKEN_PIPE;
	n_pipe->left = NULL;
	n_pipe->right = NULL;
	n_pipe->index = g_lobal_minishell.pipes_nbr;
	nodes_link((t_tree *)n_pipe, root);
}

void	new_op(t_tree **root, int type)
{
	t_op	*n_op;

	n_op = malloc(sizeof(t_op));
	n_op->type = type;
	n_op->left = NULL;
	n_op->right = NULL;
	nodes_link((t_tree *)n_op, root);
}
