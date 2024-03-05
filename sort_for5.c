/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:05:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/12 13:05:26 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_position(t_list **stack_a)
{
	int		tmp_content;
	t_list	*tmp_node;
	int		pos;
	int		count;

	if (stack_a == NULL)
		return (0);
	*stack_a = get_first_node(*stack_a);
	tmp_node = *stack_a;
	tmp_content = tmp_node->content;
	pos = 0;
	count = 0;
	while (tmp_node)
	{
		if (tmp_node->content < tmp_content)
		{
			pos = count;
			tmp_content = tmp_node->content;
		}
		tmp_node = tmp_node->next;
		count++;
	}
	return (pos);
}

void	push_min(t_list **stack_a, t_list **stack_b, int pos, int len)
{
	if (pos <= (len - 1) / 2)
	{
		while (pos > 0)
		{
			execute(stack_a, stack_b, "ra", 1);
			pos--;
		}
	}
	else
	{
		while (pos < len)
		{
			execute(stack_a, stack_b, "rra", 1);
			pos++;
		}
	}
	execute(stack_a, stack_b, "pb", 1);
}

void	push_2_minimums_from_stack(t_list **stack_a, t_list **stack_b, int len)
{
	int	position;

	if (!stack_a)
		return ;
	while (len > 3)
	{
		position = get_min_position(stack_a);
		push_min(stack_a, stack_b, position, len);
		len--;
	}
}

void	sort_for5(t_list **stack_a, t_list **stack_b, int len)
{
	push_2_minimums_from_stack(stack_a, stack_b, len);
	sort_for3(stack_a, stack_b);
	while (len > 3)
	{
		execute(stack_a, stack_b, "pa", 1);
		len--;
	}
}
