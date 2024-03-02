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

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 2;
	while ((i <= (nb / 2)) && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return ((int)(i / 2));
}

int	ft_pow(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	result = nb;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

int	ft_log2(int nb)
{
	int	i;

	i = 1;
	while (ft_pow(2, i) < nb)
		i++;
	return (i);

}

int	get_optimal_step(int len)
{
	return (ft_sqrt(len) + ft_log2(len));
}

int	stack_max(t_list *stack)
{
	int	tmp;

	stack = get_first_node(stack);
	if (!stack)
		return (0); //need to fix
	tmp = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (stack->content > tmp)
			tmp = stack->content;
		stack = stack->next;
	}
	return (tmp);
}

void	sort(t_list **stack_a, t_list **stack_b, int *ar, int arr_len)
{
	int	i;
	int	step;
	int	count;

	i = 0;
	count = 0;
	// =======for printing array==========
	// while (i < arr_len)
	// {
	// 	printf("arr[%d] = %d\n",i, ar[i]);
	// 	i++;
	// }
	// i = 0;
	// step = get_optimal_step(arr_len);
	step = 15;
	while ((*stack_a) != NULL && i < arr_len)
	{
		if ((*stack_a)->content < ar[i] || (*stack_a)->content < ar[i + step])
		{
			count ++;
			execute(stack_a, stack_b, "pb");
			if ((*stack_a) && (*stack_a)->content < ar[i])
			{
				execute(stack_a, stack_b, "rb");
			}
			i++;
		}
		else
			execute(stack_a, stack_b, "ra");
		if (i + step >= arr_len)
			step--;
		if ((*stack_a) && (*stack_a)->content > stack_max(*stack_b) && is_sorted(*stack_a))
			break ;
	}
	//  print_2stacks(*stack_a, *stack_b);
	// sort_for5(stack_a, stack_b);

	// print_2stacks(*stack_a, *stack_b);
	// printf("count = %d\n", count);
	selection_sort(stack_a, stack_b, count);
	// printf("max = %d\n", stack_max(*stack_a));
	// print_2stacks(*stack_a, *stack_b);
}
