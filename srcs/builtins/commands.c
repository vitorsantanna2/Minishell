/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:39:10 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 13:21:19 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_commands(char **args, int n_command)
{
	int	i;
	char ***res_split;

	i = 0;
	res_split = malloc(sizeof(char **) * n_command);
	while (i < n_command)
	{
		res_split[i] = ft_split(args[i], ' ');
		i++;
	}
	exec_commands(res_split, n_command);
}
void	exec_commands(char ***res_split, int n_command)
{
	int i;

	i = 0;
	if (i < n_command)
	{
		if (!ft_strcmp(res_split[n_command - 1][0], "echo"))
			echo(res_split[n_command - 1], count(res_split[n_command - 1]));
		else if (!ft_strcmp(res_split[i][0], "echo"))
			echo(res_split[i], count(res_split[i]));
		else if (!ft_strcmp(res_split[i][0], "pwd"))
			pwd();
		else if(!ft_strcmp(res_split[i][0], "cd"))
			cd(res_split[i]);
				

		i++;
	}
}
