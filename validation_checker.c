/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:14:30 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/05 14:14:31 by yuhayrap         ###   ########.fr       */
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

int	is_valid_command(char *command)
{
	if (ft_strcmp(command, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(command, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(command, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(command, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(command, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(command, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rrr\n") == 0)
		return (1);
	else
		return (0);
}
