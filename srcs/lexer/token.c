/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:51:31 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 06:14:38 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	verify_token(t_token *tokens, char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		tokens[i].value = string[i];
		if (!ft_strcmp(string[i], "<<"))
			tokens[i].type = OPERATOR;
		else if (!ft_strcmp(string[i], ">>"))
			tokens[i].type = OPERATOR;
		else if (!ft_strcmp(string[i], "<"))
			tokens[i].type = OPERATOR;
		else if (!ft_strcmp(string[i], ">"))
			tokens[i].type = OPERATOR;
		else if (!ft_strcmp(string[i], "|"))
			tokens[i].type = OPERATOR;
		else
			tokens[i].type = STRING;
		i++;
	}
}

void	start_lexer(char *prompt)
{
	char **s;
	int	i;

	if (!prompt)
		return	;
	s = ft_split(prompt, ' ');
	i = count(s);
	create_tokens(s, i);
}

void	create_tokens(char **string, int i)
{
	t_token	*tokens;
	int		c;

	c = 0;
	tokens = malloc(sizeof(t_token *) * i + 1);
	tokens = (t_token *) {0};
	if (!tokens)
		return ;
	verify_token(tokens, string);
	free(string);
	//free(tokens);
}
