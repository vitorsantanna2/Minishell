/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 06:21:27 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 08:29:04 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

int		count_quotes(char *prompt);
char	*search_quotes(char *prompt);
void	start_parse(t_token *tokens, int i);
void	join_tokens(t_token *tokens, int size, int n_command);
#endif

