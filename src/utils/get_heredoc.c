/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:05:25 by tialbert          #+#    #+#             */
/*   Updated: 2025/01/19 19:21:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

static int	read_here_doc(t_delim *delim, int inp_pipe,
						t_envp *envp, t_tree *tree)
{
	char	*line;

	if (!is_redir_valid(delim->delim))
		return (-1);
	end_heredoc(envp, inp_pipe, tree, delim);
	line = readline(">");
	line = clean_str(line, envp, 1);
	while (1)
	{
		if (!line)
			break ;
		if (ft_strncmp(delim->delim, line, lencmp(delim->delim, line)) == 0)
			return (free(line), 0);
		if (write(inp_pipe, line, ft_strlen(line)) == -1
			|| write(inp_pipe, "\n", 1) == -1)
			return (-1);
		free(line);
		line = readline(">");
		line = clean_str(line, envp, 1);
	}
	free(line);
	printf(HEREDOC_EOF" (wanted '%s')\n", delim->delim);
	g_exit_code = 0;
	return (-1);
}

void	prep_heredoc(t_delim *delim, t_tree *tree, int *inp_pipe, t_envp *envp)
{
	signal_heredoc();
	close(inp_pipe[0]);
	quotes_pairs(delim->delim, envp, 0);
	remove_quotes(&(delim->delim), 0, envp);
	if (read_here_doc(delim, inp_pipe[1], envp, tree) == -1)
	{
		free(delim->delim);
		free(delim);
		close(inp_pipe[1]);
		exit_failure(tree, NULL, envp);
	}
	close(inp_pipe[1]);
	free(delim->delim);
	free(delim);
	exit_success(tree, -1, envp);
}
