/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:19:48 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/09 15:54:31 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum s_type {
	NONE,
	COMMAND,
	STRING,
	SPACE,
}	t_type;

typedef struct s_token
{
	t_type	type;
	char    *string;
	char	value;
}	t_token;

//void	lexer(char *input, t_token *tokens);
//void	init_malloc(char *input);
//void	print(t_token *tokens);
//void	is_command(char **input, size_t *i, t_token *tokens);
//void	is_space(char **input);
//void	is_string(char **input, size_t *i, t_token *tokens);
#endif
