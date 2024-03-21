/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_dublicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:55:44 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:55:46 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_dublicates(t_list *stack)
{
	int		tmp_content;
	t_list	*tmp_node;

	if (!stack)
		return ;
	stack = get_first_node(stack);
	tmp_node = stack;
	while (tmp_node)
	{
		tmp_content = stack->content;
		while (stack)
		{
			stack = stack->next;
			if (stack && tmp_content == stack->content)
				ft_error(stack, NULL);
		}
		tmp_node = tmp_node->next;
		stack = tmp_node;
	}
}
