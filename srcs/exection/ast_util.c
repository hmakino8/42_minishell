/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasano <tasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:59:00 by tasano            #+#    #+#             */
/*   Updated: 2023/01/11 13:37:18 by tasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "exec.h"
#include <stdlib.h>
#include "libft.h"

t_cmd *convert_cmd(t_cmd *lst)
{
	t_cmd *content;
	t_cmd *init;
	t_cmd *top;

	init = lst;
	top = lst;
	while (init->piped_cmd)
	{
		content = init->piped_cmd;
		init->piped_cmd = content->piped_cmd;
		content->piped_cmd = top;
		top = content;
	}
	return (top);
}