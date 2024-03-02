/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:05:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/12 13:05:26 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for3(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content < (*stack_a)->next->content && \
		(*stack_a)->content > (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "rra");
	else if ((*stack_a)->content < (*stack_a)->next->content && \
		(*stack_a)->content < (*stack_a)->next->next->content)
	{
		execute(stack_a, stack_b, "rra");
		execute(stack_a, stack_b, "sa");
	}
	else if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->content < (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "sa");
	else if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->content > (*stack_a)->next->next->content && \
		(*stack_a)->next->content < (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "ra");
	else
	{
		execute(stack_a, stack_b, "sa");
		execute(stack_a, stack_b, "rra");
	}

}
