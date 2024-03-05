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
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->content < (*stack_a)->next->content && \
		(*stack_a)->content > (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "rra", 1);
	else if ((*stack_a)->content < (*stack_a)->next->content && \
		(*stack_a)->content < (*stack_a)->next->next->content)
	{
		execute(stack_a, stack_b, "rra", 1);
		execute(stack_a, stack_b, "sa", 1);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->content < (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "sa", 1);
	else if ((*stack_a)->content > (*stack_a)->next->content && \
		(*stack_a)->content > (*stack_a)->next->next->content && \
		(*stack_a)->next->content < (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "ra", 1);
	else
	{
		execute(stack_a, stack_b, "sa", 1);
		execute(stack_a, stack_b, "rra", 1);
	}

}
