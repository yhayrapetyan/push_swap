/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:48 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/26 16:40:52 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	printf("ra\n");
	rotate(stack_a, 0);
}

void	rb(t_list **stack_b)
{
	printf("rb\n");
	rotate(stack_b, 0);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	printf("rr\n");
	rotate(stack_a, 0);
	rotate(stack_b, 0);
}