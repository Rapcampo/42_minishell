/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:18:54 by tialbert          #+#    #+#             */
<<<<<<< HEAD:includes/minishell.h
/*   Updated: 2024/10/31 23:18:09 by rapcampo         ###   ########.fr       */
=======
/*   Updated: 2024/11/09 15:05:23 by tialbert         ###   ########.fr       */
>>>>>>> 71ce289d75c5a9ae06a9d8fa17370ae53fa319ee:Include/minishell.h
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
<<<<<<< HEAD:includes/minishell.h
# include <signal.h>
# include "macro.h"
# include "libft.h"
# include "execution.h"
=======
# include "../libft/ft_printf.h"
# include "parser.h"
# include "cleanup.h"
>>>>>>> 71ce289d75c5a9ae06a9d8fa17370ae53fa319ee:Include/minishell.h

# define PIPE	1
# define LIST	2
# define DELIM	3
# define CMD	4
# define REDIR	5

typedef struct s_tree {
	int	type;
}				t_tree;

typedef struct s_pipe {
	int				type;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_pipe;

typedef struct s_lst {
	int				type;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_lst;

typedef struct s_delim {
	int				type;
	char			*delim;
	struct s_tree	*right;
}				t_delim;

typedef struct s_cmd {
	int		type;
	char	*cmd;
	char	**opt;
}				t_cmd;

typedef struct s_redir {
	int				type;
	char			*file;
	int				mode;
	struct s_tree	*right;
}				t_redir;


/* ************************************************************************** */
/*                            EXECUTION                                       */
/* ************************************************************************** */

<<<<<<< HEAD:includes/minishell.h
/* ************************************************************************** */
/*                            FT_CMDS                                         */
/* ************************************************************************** */
void			ft_echo(t_tokens *token_lst, int *pipe);
void			ft_pwd(int *pipe);
void			ft_cd(t_tokens *token_lst);
//placeholder
void			ft_env(t_tokens *token_lst, int *pipe);
void			ft_unset(t_tokens *token_lst, int *pipe);
void			ft_export(t_tokens *token_lst, int *pipe);
=======
void			execution(t_tree *tree, int fd);
void			exec_pipe(t_tree *tree, int fd);
void			exec_delim(t_tree *tree, int fd);
void			exec_list(t_tree *tree, int fd);
void			exec_redir(t_tree *tree, int fd);
// void			ft_echo(t_tokens *token_lst, int *pipe);
// void			ft_pwd(int *pipe);
// void			ft_cd(t_tokens *token_lst);
>>>>>>> 71ce289d75c5a9ae06a9d8fa17370ae53fa319ee:Include/minishell.h

/* ************************************************************************** */
/*                            CMD UTILS                                       */
/* ************************************************************************** */
// void			dollar_sub(t_tokens *token_lst, int type);

#endif
