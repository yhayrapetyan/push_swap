/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:02:01 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 15:02:02 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int f)
{
	if (f == 1)
		write(1, "sa\n", 3);
	swap(stack_a);
}

void	sb(t_list **stack_b, int f)
{
	if (f == 1)
		write(1, "sb\n", 3);
	swap(stack_b);
}

void	ss(t_list **stack_a, t_list **stack_b, int f)
{
	if (f == 1)
		write(1, "ss\n", 3);
	swap(stack_a);
	swap(stack_b);
}
