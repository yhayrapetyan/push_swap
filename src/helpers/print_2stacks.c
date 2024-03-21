/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:43:08 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:43:10 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
