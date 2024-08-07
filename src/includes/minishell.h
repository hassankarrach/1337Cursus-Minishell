#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include "../utils/libft/libft.h"

// inner includes ===>
# include "./tokenizer.h"
# include "./garbage_collector.h"
# include "./parser.h"

// colors         ===>
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"

typedef struct s_minishell
{
    char         *line;
    t_token      *tokens;
    garbage_node *garbage_head;
}   t_minishell;

extern t_minishell global_minishell;


//expander
void	handle_expand_asterisk_wildcard(t_token **list, char *pattern);
char    **get_all_files_in_curr_dir();
int     is_containing_asterisk(char *str);

#endif