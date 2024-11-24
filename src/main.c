/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:50:12 by tialbert          #+#    #+#             */
/*   Updated: 2024/11/24 21:52:36 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

//TODO: Verify if fd 1 is a terminal (that should be the standard)
//TODO: Check if this is the best way to have access to the envirenment variables
//TODO: cd must execute in the parent process (it does not work with pipes and ';'), all other cmds execute in child processes
int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_tree	*tree;
	t_envp	*envp_lst;

	(void) argc;
	(void) argv;
	envp_lst = arr_to_lst(env);
	while (check_end() != 0)
	{
		input = readline(get_prompt());
		// TODO: create signal handling
		if (signal != 0)
			handle_signal(signal);
		if (input != NULL)
		{
			tree = tokenisation(input);
			free(input);
			execution(tree, -1, envp_lst);
			clear_tree(tree);
		}
	}
}
