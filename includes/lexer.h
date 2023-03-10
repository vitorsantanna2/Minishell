/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:19:48 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 09:11:52 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum s_type {
	NONE,
	STRING,
	LEFT_DOUBLE,
	RIGHT_DOUBLE,
	LEFT,
	RIGHT,
	PIPE,
}	t_type;

typedef struct s_token
{
	t_type	type;
	char    *value;
}	t_token;

void	start_lexer(char *input);
int		count(char **result);
void	create_tokens(char **string, int i, t_token **tokens);
void	verify_token(t_token *tokens, char **string, int size);

#endif
