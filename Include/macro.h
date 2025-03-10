/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:13:57 by rapcampo          #+#    #+#             */
/*   Updated: 2024/12/29 22:09:55 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H 
# define MACRO_H 

//Linux key exit codes are as folows
//0: Success
//1: General error
//2: Missuse of builtins
//126: Command cannot execute: no perms or insuficient memory etc
//127: Command not found
//128: Invalid exit argument
//128 + signum: fatal signal, ex 137 = SIGKILL + 128
//130: control C termination SIGINT
//255: exit status out of range (valid is 0 to 254)

//colour prints

# define RST "\e[0m"
# define ULI "\e[4m"
# define BLN "\e[5m"
# define BLK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YLW "\e[1;33m"
# define BLU "\e[1;34m"
# define PRP "\e[1;35m"
# define CYN "\e[1;36m"
# define WHT "\e[1;37m"
# define CLR "\e[0;39m"

//CD ERRORS

# define CD_NOT_FND "cd: No such file or directory\n"
# define CD_NO_PERM "cd: Permission denied\n"
# define CD_GEN_ERR "cd: Could not change directory\n"
# define CD_NOT_DIR "cd: File is not a directory\n"
# define CD_ERR_ARG "cd: Too many arguments\n"
# define CD_NO_HOME "cd: HOME not set\n"
# define CD_OLDPWD "cd: OLDPWD not set\n"

//PWD ERRORS

# define PWD_NO_SET "pwd: PWD not set\n"
# define PWD_NO_PRNT "pwd: could not print current directory\n"

//ENV ERRORS

# define ENV_NOFILE "env: no such file or directory\n"

//EXPORT ERRORS

# define MEM_ALLOC "export: memory allocation failure\n"
# define INVAL_ID ": is an invalid identifier\n"

//PROMPT

# define UPPER_PROMPT "╭─ \e[4;36m"
# define LP_L "\001╰─\002 \001\e[1;35m\002Minishell"
# define LP_R "\001\e[1;33m\002 $-> \001\e[0m\002 \b"

//HEREDOC ERRORS

# define SYNTAX_ERR "heredoc: syntax error near unexpected token `newline'\n"
# define HEREDOC_EOF "minishell: warning: here-doc delimited by end-of-file"

//EXIT ERRORS

# define EX_MANY_ARG "exit: too many arguments\n"
# define EX_ALPHA_ERR "exit: numeric argument required\n"

//PIPE ERRORS

# define PIPE_ERR "pipe: syntax error near unexpected token `|'\n"

//QUOTE ERRORS

# define QUOTE_ERR "quotes: unclosed quotes\n"

//REDIR ERRORS

# define REDIR_ERR "minishell: syntax error near unexpected token `newline'\n"
# define REDIR_TOK "minishell: syntax error near unexpected token `" 

//EXEC ERRORS
# define ERR_IS_DIR "minishell: "
# define REL_PATH_ERR "minishell: .: filename argument required\n"
# define REL_USAGE ".: usage: . filename [arguments]\n"

#endif
