/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:42:28 by rapcampo          #+#    #+#             */
/*   Updated: 2024/11/08 12:46:54 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
<<<<<<< HEAD:includes/execution.h
# include <signal.h>
=======
>>>>>>> 71ce289d75c5a9ae06a9d8fa17370ae53fa319ee:Include/execution.h

typedef	struct s_exec 
{
	int		exit_status;
	char	*cwd;
<<<<<<< HEAD:includes/execution.h
}		t_exec;

//concatanation
char	*ft_stpcpy(char *restrict dst, const char *restrict src);
void	*ft_mempcpy(void *dest, const void *src, size_t n);

//memory safety
void	ft_freematrix(char **matrix);
=======
};
>>>>>>> 71ce289d75c5a9ae06a9d8fa17370ae53fa319ee:Include/execution.h


#endif
