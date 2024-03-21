/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:02:11 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 15:02:12 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int f)
{
	if (f == 1)
		write(1, "pa\n", 3);
	push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b, int f)
{
	if (f == 1)
		write(1, "pb\n", 3);
	push(stack_a, stack_b);
}
