/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:22:27 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/02 17:22:30 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_optimal_step(int len)
{
	return (ft_sqrt(len) + ft_log2(len) - 1);
}

void	sort(t_list **stack_a, t_list **stack_b, int *ar, int arr_len)
{
	int	i;
	int	step;

	i = 0;
	step = get_optimal_step(arr_len);
	while ((*stack_a) != NULL && i < arr_len)
	{
		if ((*stack_a)->content <= ar[i])
		{
			execute(stack_a, stack_b, "pb", 1);
			execute(stack_a, stack_b, "rb", 1);
			i++;
		}
		else if ((*stack_a)->content <= ar[i + step])
		{
			execute(stack_a, stack_b, "pb", 1);
			i++;
		}
		else
			execute(stack_a, stack_b, "ra", 1);
		if (i + step >= arr_len)
			step--;
	}
	selection_sort(stack_a, stack_b, arr_len);
}
