/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:18:30 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/09 15:53:16 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void lexer(char *input, t_token *tokens)
{
	size_t	i;

	i = 0;
    while (ft_strlen(input) > 0)
    {
		is_command(&input, &i, tokens);
		is_space(&input);
		is_string(&input, &i, tokens);
	}
}

void	init_malloc(char *input)
{
	t_token *tokens;
    tokens = malloc(sizeof(t_token) * (ft_strlen(input) + 1));
	lexer(input, tokens);
	print(tokens);
}

void print(t_token *tokens)
{
	int	i;
	i = 0;

    while (tokens[i].type != 0)
    {
		if (tokens[i].type == 1 || tokens[i].type == 2) 
			printf("Token %d: type = %d, value = %s\n", i, tokens[i].type, tokens[i].string);
		i++;
    }
}
