/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasano <tasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:45:00 by tasano            #+#    #+#             */
/*   Updated: 2023/01/17 00:30:16 by tasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_status(void)
{
	return (g_shell.status);
}

void	set_status(int status)
{
	g_shell.status = status % 255;
}
