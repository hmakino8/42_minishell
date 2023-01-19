/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:51:13 by hiroaki           #+#    #+#             */
/*   Updated: 2023/01/19 21:46:01 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include "util.h"
#include "minishell.h"

int	rl_routine(void)
{
	if (g_shell.sig_no == 0)
		return (0);
	if (g_shell.child_interrupted)
	{
		g_shell.status = 130;
		g_shell.child_interrupted = 0;
	}
	else
	{
		if (g_shell.status == 0)
			g_shell.status = 1;
		rl_done = 1;
		rl_redisplay();
	}
	g_shell.sig_no = 0;
	return (0);
}

void	set_rl_routine(void)
{
	extern int	_rl_echo_control_chars;

	_rl_echo_control_chars = 0;
	rl_event_hook = rl_routine;
}

int	rl_heredoc_event(void)
{
	if (g_shell.sig_no == 0)
		return (0);
	g_shell.status = 1;
	g_shell.heredoc_interrupted = 1;
	rl_done = 1;
	g_shell.sig_no = 0;
	return (0);
}

void	set_rl_heredoc_event(void)
{
	extern int	_rl_echo_control_chars;

	_rl_echo_control_chars = 0;
	rl_event_hook = rl_heredoc_event;
}
