/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_helpers_NO-NORME.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:27:57 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/10 18:27:59 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{

	stack = get_first_node(stack);
	while (stack)
	{
		printf("%d", stack->content);
		// if (stack->content < 0)
		// {
		// 	stack->content *= -1;
		// 	printf("minus");
		// }
		// while (i < stack->content)
		// {
		// 	printf("*");
		// 	i++;
		// }
		printf("\n");
		stack = stack->next;
	}
}

void	print_2stacks(t_list *stack_a, t_list *stack_b)
{
	stack_a = get_first_node(stack_a);
	stack_b = get_first_node(stack_b);
	printf("=~=~==~==~==~==~==~==~==~==~==~==~==~==~==~==~=~\n");
	printf("                 PRINTING STACKS                \n");
	printf("=~=~==~==~==~==~==~==~==~==~==~==~==~==~==~==~=~\n");
	if (stack_a)
	{
		printf("STACK A");
		if (stack_b)
		{
			printf("\t\tSTACK B");
		}
		printf("\n");
		while (stack_a)
		{
			printf("%d", stack_a->content);
			if (stack_b)
			{
				printf("\t\t%d", stack_b->content);
				stack_b = stack_b->next;
			}
			printf("\n");
			stack_a = stack_a->next;
		}
		while (stack_b)
		{
			printf("\t\t%d", stack_b->content);
			stack_b = stack_b->next;
			printf("\n");
		}
	}
	else
	{

		printf("STACK B\n");
		while (stack_b)
		{
			printf("%d\n", stack_b->content);
			stack_b = stack_b->next;
		}
	}
	printf("================================================\n");
	printf("================================================\n\n");
}
