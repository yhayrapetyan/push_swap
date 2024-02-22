/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:05:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/12 13:05:26 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	int	tmp;

	stack = get_first_node(stack);
	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	push(t_list **from, t_list **to)
{
	if (from == NULL || to == NULL)
		return ;
	*from = get_last_node(*from);
	*to = get_last_node(*to);
	if (*from == NULL)
		return ;
	*to = add_node(*to, (*from)->content);

}

void	rotate(t_list **stack, int reversed)
{
	t_list	*tmp;

	*stack = get_first_node(*stack);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
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

void	execute(t_list *stack_a, t_list *stack_b, char *command)
{
	if (ft_strcmp(command, "sa"))
		swap(stack_a);
	else if (ft_strcmp(command, "sb"))
		swap(stack_b);
	else if (ft_strcmp(command, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strcmp(command, "pa"))
		push(&stack_a, &stack_b);
	else if (ft_strcmp(command, "pb"))
		push(&stack_b, &stack_a);
	else if (ft_strcmp(command, "ra"))
		rotate (&stack_a, 0);
	else if (ft_strcmp(command, "rb"))
		rotate (&stack_b, 0);
	else if(ft_strcmp(command, "rr"))
	{
		rotate (&stack_a, 0);
		rotate(&stack_b, 0);
	}
	else if (ft_strcmp(command, "rra"))
		rotate (&stack_a, 1);
	else if (ft_strcmp(command, "rrb"))
		rotate (&stack_b, 1);
	else if(ft_strcmp(command, "rrr"))
	{
		rotate (&stack_a, 1);
		rotate(&stack_b, 1);
	}
}

// void	push_swap(t_list *stack_a, t_list *stack_b)
// {
// 	stack_a = get_first_node(stack_a);
// 	if (is_sorted(stack_a))
// 		return ;
// }
