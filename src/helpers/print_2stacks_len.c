/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2stacks_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:42:46 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:42:48 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stars(int len)
{
	int			i;
	long long	cpy;

	i = 0;
	cpy = (long long)len;
	if (cpy < 0)
	{
		cpy *= -1;
		printf("minus");
	}
	while (i < cpy)
	{
		printf(".");
		i++;
	}
}

void	print_2stacks_len(t_list *stack_a, t_list *stack_b)
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
			print_stars(stack_a->content);
			if (stack_b)
			{
				printf("\t\t");
				print_stars(stack_b->content);
				stack_b = stack_b->next;
			}
			printf("\n");
			stack_a = stack_a->next;
		}
		while (stack_b)
		{
			printf("\t\t");
			print_stars(stack_b->content);
			printf("\n");
		}
	}
	else
	{
		printf("STACK B\n");
		while (stack_b)
		{
			print_stars(stack_b->content);
			printf("\n");
			stack_b = stack_b->next;
		}
	}
	printf("================================================\n");
	printf("================================================\n\n");
}
