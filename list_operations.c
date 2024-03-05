/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:48 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/26 16:40:52 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	*stack = get_first_node(*stack);
	if ((*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
}

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
