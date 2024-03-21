/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:14:30 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/05 14:14:31 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
