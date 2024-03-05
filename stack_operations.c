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

void	rra(t_list **stack_a, int f)
{
	if (f == 1)
		write(1, "rra\n", 4);
	rotate(stack_a, 1);
}

void	rrb(t_list **stack_b, int f)
{
	if (f == 1)
		write(1, "rrb\n", 4);
	rotate(stack_b, 1);
}

void	rrr(t_list **stack_a, t_list **stack_b, int f)
{
	if (f == 1)
		write(1, "rrr\n", 4);
	rotate(stack_a, 1);
	rotate(stack_b, 1);
}
