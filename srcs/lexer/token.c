/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:51:31 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 09:28:35 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	verify_token(t_token *tokens, char **string, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tokens[i].value = string[i];
		if (!ft_strcmp(string[i], "<<"))
			tokens[i].type = LEFT_DOUBLE;
		else if (!ft_strcmp(string[i], ">>"))
			tokens[i].type = RIGHT_DOUBLE;
		else if (!ft_strcmp(string[i], "<"))
			tokens[i].type = LEFT;
		else if (!ft_strcmp(string[i], ">"))
			tokens[i].type = RIGHT;
		else if (!ft_strcmp(string[i], "|"))
			tokens[i].type = PIPE;
		else
			tokens[i].type = STRING;
		i++;
	}
}

int	count(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		i++;
	return (i);
}

void	start_lexer(char *prompt)
{
	char **s;
	int	i;
	int c;

	c = 0;
	if (!prompt)
		return	;
	s = ft_split(prompt, ' ');
	i = count(s);
	t_token *tokens = NULL;
	create_tokens(s, i, &tokens);
}

void	create_tokens(char **string, int i, t_token **tokens)
{

	*tokens = malloc(sizeof(t_token) * i + 1);
	verify_token(*tokens, string, i);
	start_parse(*tokens, i);
}
