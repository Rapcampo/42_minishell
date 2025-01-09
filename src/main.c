/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:50:12 by tialbert          #+#    #+#             */
/*   Updated: 2025/01/09 21:48:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	g_exit_code;

static void	dup_std(t_envp *envp)
{
	envp->fd_in = dup(STDIN_FILENO);
	envp->fd_out = dup(STDOUT_FILENO);
}

static char	*get_prompt(t_envp *envp)
{
	char	*prompt;
	char	*pwd;
	char	*tmp;

	pwd = getcwd(NULL, 4096);
	if (!pwd && search_envp(envp, "PWD"))
		pwd = ft_strdup(search_envp(envp, "PWD")->value);
	else if (!pwd && !search_envp(envp, "PWD"))
		return (ft_strdup(LOWER_PROMPT));
	tmp = ft_calloc(1,
			(ft_strlen(pwd) + ft_strlen(LOWER_PROMPT) + 2));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, pwd, ft_strlen(pwd) + ft_strlen(LOWER_PROMPT) + 2);
	prompt = ft_strjoin(tmp, "\n"LOWER_PROMPT);
	ft_free(tmp);
	ft_free(pwd);
	return (prompt);
}

static void	input_reader(t_envp *envp)
{
	t_tree	*tree;
	char	*input;
	char	*prompt;

	prompt = get_prompt(envp);
	input = readline(prompt);
	while (1)
	{
		if (!input)
		{
			ft_free(prompt);
			return ;
		}
		add_history(input);
		tree = tokenisation(input, envp);
		save_root(envp, tree);
		ft_free(input);
		ft_free(prompt);
		execution(tree, -1, envp);
		clear_tree(tree);
		prompt = get_prompt(envp);
		input = readline(prompt);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_envp	*envp_lst;

	((void)argc, (void)argv);
	envp_lst = arr_to_lst(env);
	dup_std(envp_lst);
	signal_parent();
	update_shlvl(envp_lst);
	input_reader(envp_lst);
	rl_clear_history();
	clear_envp(envp_lst);
	printf("exit\n");
	return (g_exit_code);
}
