/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:15:33 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/09 15:54:42 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	//char *args;
	char *prompt;

	while (1)
	{
		prompt = readline("\033[32m ➜\033[1;34m Minishell \033[1;33m✗ \033[0m");
		if (!ft_strcmp(prompt, "clear"))
				printf("\033[2J\033[1;1H\033[K");
	}
}
