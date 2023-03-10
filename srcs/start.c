/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:15:33 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 12:39:57 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
	char *prompt;

	(void) argv;
	if (argc > 1)
		error();
	while (1)
	{
		prompt = readline("\033[32m â\033[0;34m Minishell \033[1;33mâ \033[0m");
		start_lexer(ft_strdup(prompt));
		free(prompt);
	}
}
