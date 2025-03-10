/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:20:52 by tialbert          #+#    #+#             */
/*   Updated: 2025/01/18 23:43:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

static char	**get_opt(t_cmd *cmd, t_tree *tree, char **input, t_envp *envp)
{
	int		i;
	char	**input_cpy;

	input_cpy = NULL;
	i = 0;
	while (i < cmd->num_opt)
	{
		if (redir_check(*input) == 0)
		{
			cmd->opt[i] = malloc(ft_strlen(*input) + 1);
			if (cmd->opt[i] == NULL)
				clean_cmd((t_tree *) cmd, tree, envp);
			ft_strlcpy(cmd->opt[i++], *input, ft_strlen(*input) + 1);
		}
		else
			input_cpy = ignore_redir(&input, input_cpy);
		if (*input != NULL)
			input++;
	}
	cmd->opt[i] = NULL;
	if (input_cpy != NULL)
		return (input_cpy);
	return (input);
}

t_tree	*cmd_node(t_tree *tree, char **input, t_envp *envp)
{
	t_cmd	*cmd;

	cmd = (t_cmd *) safe_alloc(sizeof(*cmd), 1, tree, envp);
	cmd->type = CMD;
	cmd->cmd = (char *) safe_alloc(ft_strlen(*input) + 1, 1, tree, envp);
	ft_strlcpy(cmd->cmd, *input, ft_strlen(*input) + 1);
	cmd->num_opt = count_opt(input);
	cmd->opt = malloc((cmd->num_opt + 1) * sizeof(char *));
	if (cmd->opt == NULL)
		clean_cmd((t_tree *) cmd, tree, envp);
	input = get_opt(cmd, tree, input, envp);
	if (*input != NULL && ft_strncmp(*input, "||", lencmp(*input, "||")) == 0)
		input++;
	if (tree != NULL)
	{
		org_tree(tree, (t_tree *) cmd);
		tree = token_dist(tree, envp, input);
		return (tree);
	}
	tree = token_dist((t_tree *) cmd, envp, input);
	return (tree);
}

t_tree	*delim_node(t_tree *tree, char **input, t_envp *envp)
{
	t_delim	*delim;

	input++;
	delim = (t_delim *) safe_alloc(sizeof(*delim), 1, tree, envp);
	delim->type = DELIM;
	delim->fd = -1;
	delim->delim = malloc(ft_strlen(*input) + 1);
	if (delim->delim == NULL)
	{
		free(delim);
		exit_failure(tree, NULL, envp);
	}
	bzero(delim->delim, ft_strlen(*input) + 1);
	ft_strlcpy(delim->delim, *input, ft_strlen(*input) + 1);
	if (receive_here_doc(delim, tree, envp) == -1)
		return (NULL);
	if (*input != NULL)
		input++;
	if (check_cmd(tree) == 1)
		input = ignore_opt(input);
	tree = org_delim(delim, tree);
	tree = token_dist(tree, envp, input);
	return (tree);
}

t_tree	*pipe_node(t_tree *tree, char **input, t_envp *envp)
{
	t_pipe	*pipe;

	pipe = (t_pipe *) safe_alloc(sizeof(*pipe), 1, tree, envp);
	pipe->type = PIPE;
	if (tree != NULL && tree->type == PIPE)
		tree_leafs_pipe(tree, pipe);
	else
		pipe->left = tree;
	pipe->right = NULL;
	input++;
	if (*input == NULL || **input == '|')
	{
		if (tree != NULL && tree->type != PIPE)
			clear_tree(tree);
		free(pipe);
		stat_ret(RED PIPE_ERR RST, 2);
		return (NULL);
	}
	if (tree != NULL && tree->type == PIPE)
		tree = token_dist(tree, envp, input);
	else
		tree = token_dist((t_tree *) pipe, envp, input);
	return (tree);
}

t_tree	*redir_node(t_tree *tree, char **input, int mode, t_envp *envp)
{
	t_redir	*redir;

	input++;
	redir = (t_redir *) safe_alloc(sizeof(*redir), 1, tree, envp);
	redir->type = REDIR;
	redir->file = NULL;
	if (*input != NULL)
	{
		redir->file = malloc(ft_strlen(*input) + 1);
		if (redir->file == NULL)
		{
			free(redir);
			exit_failure(tree, NULL, envp);
		}
		ft_strlcpy(redir->file, *input, ft_strlen(*input) + 1);
		if (mode == (O_WRONLY | O_CREAT))
			check_outfile(redir, mode, envp, tree);
		input++;
	}
	if (check_cmd(tree) == 1)
		input = ignore_opt(input);
	redir->mode = mode;
	tree = org_redir_read(redir, tree);
	tree = token_dist(tree, envp, input);
	return (tree);
}
