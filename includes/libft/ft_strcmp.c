/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:55:34 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/09 15:50:43 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *src, char *dst)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != ' ' && src[len])
	{
		len++;
	}
	if (len > ft_strlen(dst))
		return (1);
	else
	{
		while (i < len)
		{
			if (src[i] != dst[i])
				return (1);
			i++;
		}
		return (0);
	}
}	
