/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:02:19 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 15:02:21 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int f)
{
	if (f == 1)
		write(1, "ra\n", 3);
	rotate(stack_a, 0);
}

void	rb(t_list **stack_b, int f)
{
	if (f == 1)
		write(1, "rb\n", 3);
	rotate(stack_b, 0);
}

void	rr(t_list **stack_a, t_list **stack_b, int f)
{
	if (f == 1)
		write(1, "rr\n", 3);
	rotate(stack_a, 0);
	rotate(stack_b, 0);
}
