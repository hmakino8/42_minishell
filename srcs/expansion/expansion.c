/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasano <tasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:21:48 by tasano            #+#    #+#             */
/*   Updated: 2023/01/13 18:40:19 by tasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libft.h"

char *join_parameter(char *str, char *val, size_t i, size_t parameter_len)
{
	char *before;
	char *after;
	char *tmp;

	before = get_before(str, i);
	after = get_after(str, i + parameter_len);
	free_strval(&str);
	tmp = ft_strjoin(before, val);
	str = ft_strjoin(tmp, after);
	free_strval(&before);
	free_strval(&after);
	free_strval(&tmp);
	return (str);
}

char *set_parameter(char *str, size_t i)
{
	char *parameter;
	char *val;

	parameter = get_parameter(str + i);
	if (parameter)
	{
		val = getenv(parameter + 1);
		str = join_parameter(str, val, i, ft_strlen(parameter));
		free_strval(&parameter);
	}
	return (str);
}

char *expand(char *str)
{
	size_t i;
	char *tmp;

	i = 0;
	tmp = ft_strtrim(str, "\"");
	free_strval(&str);
	str = tmp;
	while (str[i])
	{
		if (str[i] == '$')
			str = set_parameter(str, i);
		else
			i++;
	}
	if (str && !str[0])
		return (NULL);
	return (str);
}

int expansion(t_cmd *cmd)
{
	size_t i;
	t_redirect *tmp_redirect;

	while (cmd)
	{
		tmp_redirect = cmd->redirect;
		while (tmp_redirect)
		{
			if (tmp_redirect->expnad_type == EXPANDABLE)
				tmp_redirect->filename = expand(tmp_redirect->filename);
			tmp_redirect = tmp_redirect->next;
		}
		i = 0;
		while (cmd->argc != 0 && cmd->cmd[i])
		{
			if (!is_expandble(cmd->cmd[i]))
				cmd->cmd[i] = expand(cmd->cmd[i]);
			i++;
		}
		cmd = cmd->piped_cmd;
	}
	return (0);
}