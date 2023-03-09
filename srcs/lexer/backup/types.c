/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:07:10 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/09 13:45:50 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void is_command(char **input, size_t *i, t_token *tokens)
{
	if (!ft_strcmp(*input, "echo"))
	{
		tokens[*i].type = COMMAND;
		tokens[*i].string = "echo";
		*i = *i + 1;
		*input = ft_remove(*input, 4);
	}
	else if (!ft_strcmp(*input, "cd"))
	{
		tokens[*i].type = COMMAND;
		tokens[*i].string = "cd";
		*i = *i + 1;
		*input = ft_remove(*input, 2);
	}
	else if (!ft_strcmp(*input, "pwd"))
	{
		tokens[*i].type = COMMAND;
		tokens[*i].string = "pwd";
		*i = *i + 1;
		*input = ft_remove(*input, 3);
	}
}

void is_string(char **input, size_t *i, t_token *tokens)
{
    size_t len;
	size_t	x;
	char *string;
	char *copy;

	x = 0;
	len = 0;
	copy = *input;
	if (ft_strcmp(*input, "echo") || ft_strcmp(*input, "cd") || ft_strcmp(*input, "pwd"))
	{
		while (copy[len] != ' ' && copy[len])
		{
			len++;
		}
		string = malloc(sizeof(char *) * (len));
		while (x < len)
		{
			string[x] = copy[x];
			x++;
		}
		//string[x] = '\0';
		tokens[*i].type = STRING;
		tokens[*i].string = string;
		*i = *i + 1;
		*input = ft_remove(*input, len + 1);
		//free(string);
	}
}

void	is_space(char **input)
{
	if (*input[0] == ' ')
	{
		*input = ft_remove(*input, 1);
	}
}
