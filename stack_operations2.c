/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:48 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/26 16:40:52 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	printf("sa\n");
	swap(stack_a);
}

void	sb(t_list **stack_b)
{
	printf("sb\n");
	swap(stack_b);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	printf("ss\n");
	swap(stack_a);
	swap(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	printf("pa\n");
	push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	printf("pb\n");
	push(stack_a, stack_b);
}
