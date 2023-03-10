/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:49:36 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 13:07:14 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	echo(char **args, int size)
{
	char	*message;
	int		flag;
	int		i;

	i = 1;
	flag = 0;
	if (size < 2)
	{
		printf("\n");
		return	;
	}
	while (!ft_strcmp(args[i], "-n"))
	{
		i++;
		flag = 1;
	}
	message = malloc(sizeof(char) * size + 1);
	message = args[i];
	while (++i < size)
	{
		message = ft_strjoin(message, " ");
		message = ft_strjoin(message, args[i]);
	}
	if (flag == 1)
		printf("%s", message);
	else
		printf("%s\n", message);
}
