/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:16:32 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 14:16:34 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	*stack_from = get_first_node(*stack_from);
	*stack_to = get_first_node(*stack_to);
	tmp = (*stack_from)->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	(*stack_from)->next = *stack_to;
	if (*stack_to != NULL)
		(*stack_to)->prev = *stack_from;
	*stack_to = *stack_from;
	*stack_from = tmp;
	return ;
}
