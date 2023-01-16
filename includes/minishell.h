/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasano <tasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:45 by asanotomoki       #+#    #+#             */
/*   Updated: 2023/01/17 00:52:35 by tasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
//# include <readline/readline.h>
//# include <readline/history.h>
# include "err.h"
# include "libft.h"
# include "util.h"

#define PROMPT "minish$ "
# define SHELL "minish"

typedef struct s_shell
{
	int	status;
	int	heredoc_interrupt;
} t_shell;

t_shell g_shell;

#endif
