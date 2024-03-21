/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:16:52 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 14:16:53 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute(t_list **stack_a, t_list **stack_b, char *command, int f)
{
	if (ft_strcmp(command, "sa") == 0)
		sa(stack_a, f);
	else if (ft_strcmp(command, "sb") == 0)
		sb(stack_b, f);
	else if (ft_strcmp(command, "ss") == 0)
		ss(stack_a, stack_b, f);
	else if (ft_strcmp(command, "pa") == 0)
		pa(stack_a, stack_b, f);
	else if (ft_strcmp(command, "pb") == 0)
		pb(stack_a, stack_b, f);
	else if (ft_strcmp(command, "ra") == 0)
		ra(stack_a, f);
	else if (ft_strcmp(command, "rb") == 0)
		rb(stack_b, f);
	else if (ft_strcmp(command, "rr") == 0)
		rr(stack_a, stack_b, f);
	else if (ft_strcmp(command, "rra") == 0)
		rra(stack_a, f);
	else if (ft_strcmp(command, "rrb") == 0)
		rrb(stack_b, f);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(stack_a, stack_b, f);
}

