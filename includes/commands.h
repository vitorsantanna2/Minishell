/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:20:31 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/10 13:23:10 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

void	split_commands(char **args, int n_command);
void	exec_commands(char ***re_split, int n_command);
void	echo(char **args, int size);
void	pwd(void);
void	cd(char **path);
#endif
