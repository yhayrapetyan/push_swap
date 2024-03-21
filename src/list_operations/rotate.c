/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:16:43 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 14:16:44 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, int reversed)
{
	t_list	*tmp;

	if (stack == NULL)
		return ;
	*stack = get_first_node(*stack);
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	if (!reversed)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->prev = get_last_node(*stack);
		get_last_node(*stack)->next = tmp;
		tmp->next = NULL;
	}
	else
	{
		*stack = get_last_node(*stack);
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = tmp;
		tmp->prev = *stack;
	}
}

