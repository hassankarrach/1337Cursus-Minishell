/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbasri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:46:27 by aelbasri          #+#    #+#             */
/*   Updated: 2024/05/06 15:46:29 by aelbasri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../utils/libft/libft.h"
# include "./error.h"
# include "./tokenizer.h"
# include "./parser.h"
# include "./executor.h"
# include "./garbage_collector.h"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"

typedef struct s_minishell
{
	int				error;
	int				pipes_nbr;
	int				*quote;
	int				a_counter;
	char			**my_env;
	int				status;
	int				sig;
	pid_t			main_pid;
	int				old_stdin;
	int				old_stdout;
	char			**env;
	t_environment	*environment;
	t_token			*tokens;
	char			*line;
	t_tree			*root;
}	t_minishell;

extern t_minishell	g_lobal_minishell;

void	init_minishell(char *input);
int		check_input(char **input);
void	init(char **env);
void	close_io(void);
int		check_single_cmd(int flag);

#endif
