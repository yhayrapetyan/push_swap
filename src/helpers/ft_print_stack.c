/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:42:31 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:42:32 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	print_stack(t_list *stack)
{

	stack = get_first_node(stack);
	while (stack)
	{
		printf("%d", stack->content);
		printf("\n");
		stack = stack->next;
	}
}
