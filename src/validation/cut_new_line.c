/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_new_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:34:10 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/05 12:34:13 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*cut_new_line(char	*command)
{
	int		i;
	char	*new_command;

	new_command = (char *)malloc(ft_strlen(command));
	if (!new_command)
		return (NULL);
	i = 0;
	while (command[i] && command[i] != '\n')
	{
		new_command[i] = command[i];
		i++;
	}
	new_command[i] = '\0';
	free(command);
	return (new_command);
}
