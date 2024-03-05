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
	if (!arr)
		return (NULL);
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

int	*fill_arr(t_list	*stack, int	*arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = stack->content;
		i++;
		if (stack->next)
			stack = stack->next;
	}
	return (arr);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	*sorted_arr;
	int	len;

	//DO WE NEED TO CHECK ? if stack_a == NULL ????????????
	(*stack_a) = get_first_node(*stack_a);
	len = stack_len(*stack_a);
	sorted_arr = (int *)malloc(sizeof(int) * len);
	if (!sorted_arr)
		return ;
	sorted_arr = fill_arr(*stack_a, sorted_arr, len);
	sorted_arr = sort_arr(sorted_arr, len);
	(*stack_a) = get_first_node(*stack_a);
	if (is_sorted(*stack_a))
	{
		free(sorted_arr);
		return ;
	}
	if (len == 2)
		execute(stack_a, stack_b, "sa", 1);
	else if (len == 3)
		sort_for3(stack_a, stack_b);
	else if (len <= 5)
		sort_for5(stack_a, stack_b, len);
	else
		sort(stack_a, stack_b, sorted_arr, len);
	free(sorted_arr);
}
