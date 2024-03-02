/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:05:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/12 13:05:26 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_arr(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (arr[j] > arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}



void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	*sorted_arr;
	int	i;
	int	len;

	(*stack_a) = get_first_node(*stack_a);
	len = stack_len(*stack_a);
	sorted_arr = (int *)malloc(sizeof(int) * len);
	if (!sorted_arr)
		return ;
	i = 0;
	while (i < len)
	{
		sorted_arr[i] = (*stack_a)->content;
		i++;
		if ((*stack_a)->next)
			(*stack_a) = (*stack_a)->next;
	}
	sorted_arr = sort_arr(sorted_arr, len);
	i = 0;
	// =======for printing array==========
	// while (i < len)
	// {
	// 	printf("%d\n", sorted_arr[i]);
	// 	i++;
	// }
	(*stack_a) = get_first_node(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (len == 2)
		execute(stack_a, stack_b, "sa");
	else if (len == 3)
		sort_for3(stack_a, stack_b);
	else if (len <= 5)
		sort_for5(stack_a, stack_b, len);
	else
		sort(stack_a, stack_b, sorted_arr, len);
	free(sorted_arr);
}
