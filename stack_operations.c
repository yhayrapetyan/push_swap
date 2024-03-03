/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:48 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/26 16:40:52 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	printf("rra\n");
	rotate(stack_a, 1);
}

void	rrb(t_list **stack_b)
{
	printf("rrb\n");
	rotate(stack_b, 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	printf("rrr\n");
	rotate(stack_a, 1);
	rotate(stack_b, 1);
}
