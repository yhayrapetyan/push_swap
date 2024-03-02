/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:35:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/02 17:35:21 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_position(t_list **stack)
{
	int		tmp_content;
	t_list	*tmp_node;
	int		pos;
	int		count;

	*stack = get_first_node(*stack);
	tmp_node = *stack;
	tmp_content = tmp_node->content;
	pos = 0;
	count = 0;
	while (tmp_node)
	{
		if (tmp_node->content > tmp_content)
		{
			pos = count;
			tmp_content = tmp_node->content;
		}
		tmp_node = tmp_node->next;
		count++;
	}
	return (pos);
}

void	push_max(t_list **stack_a, t_list **stack_b, int pos, int len)
{
	if (pos <= (len - 1) / 2)
	{
		while (pos > 0)
		{
			execute(stack_a, stack_b, "ra");
			pos--;
		}
	}
	else
	{
		while (pos < len)
		{
			execute(stack_a, stack_b, "rra");
			pos++;
		}
	}
	execute(stack_a, stack_b, "pb");
}

void	selection_sort(t_list **stack_a, t_list **stack_b, int arr_len)
{
	int	pos;

	while (arr_len > 0)
	{
		pos = get_max_position(stack_b);
		push_max(stack_b, stack_a, pos, arr_len);
		arr_len--;
	}
}
