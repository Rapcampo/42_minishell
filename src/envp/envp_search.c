/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:45:27 by tialbert          #+#    #+#             */
/*   Updated: 2024/11/28 01:55:03 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

t_envp	*search_envp(t_envp *head, char *var)
{
	t_envp	*curr;

	if (!head)
		return (NULL);
	curr = head->next;
	while (curr)
	{
		if (ft_strncmp(curr->key, var, lencmp(curr->key, var)) == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
