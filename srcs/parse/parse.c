/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:18:30 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 12:54:30 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_parse(t_token *tokens, int i)
{
	int c;
	int	n_commands;

	c = 0;
	n_commands = 1;
	while (c < i)
	{
		if (tokens[c].type == PIPE)
			n_commands++;
		c++;
	}
	join_tokens(tokens, i, n_commands);
}

void	join_tokens(t_token *tokens, int size, int n_command)
{
	int	c;
	int cmds;
	char **res;

	c = 0;
	cmds = 0;
	res = NULL;
	res = malloc(sizeof(char *) * n_command);
	while (cmds < n_command)
	{
		res[cmds] = search_quotes(tokens[c].value);
		c++;
		while (tokens[c].type != PIPE && c < size)
		{
			res[cmds] = ft_strjoin(res[cmds], " ");
			res[cmds] = ft_strjoin(res[cmds], search_quotes(tokens[c].value));
			c++;
		}
		c++;
		cmds++;
	}
	split_commands(res, n_command);
}

int	count_quotes(char *prompt)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (prompt[i])
	{
		if (prompt[i] == '"')
			q++;
		i++;
	}
	return (q);
}

char *search_quotes(char *prompt)
{
	int	i;
	int	c;
	int	q;
	char	*res;

	i = 0;
	c = 0;
	q = count_quotes(prompt);
	res = malloc(sizeof(char *) * (ft_strlen(prompt) - q + 1));
	while (prompt[i])
	{
		if (prompt[i] == '"')
			i++;
		if (prompt[i - 1] != '"' && prompt[i] == '\'' && prompt[i + 1] != '"')
			i++;
		res[c] = prompt[i];
		c++;
		i++;
	}
	return (res);
}
