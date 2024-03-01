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

void	sort_for3(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content < (*stack_a)->next->content && 
		(*stack_a)->content > (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "rra");
	else if ((*stack_a)->content < (*stack_a)->next->content && 
		(*stack_a)->content < (*stack_a)->next->next->content)
	{
		execute(stack_a, stack_b, "rra");
		execute(stack_a, stack_b, "sa");
	}
	else if ((*stack_a)->content > (*stack_a)->next->content && 
		(*stack_a)->content < (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "sa");
	else if ((*stack_a)->content > (*stack_a)->next->content && 
		(*stack_a)->content > (*stack_a)->next->next->content &&
		(*stack_a)->next->content < (*stack_a)->next->next->content)
		execute(stack_a, stack_b, "ra");
	else 
	{
		execute(stack_a, stack_b, "sa");
		execute(stack_a, stack_b, "rra");
	}

}
int	get_min_position(t_list **stack_a)
{
	int		tmp_content;
	t_list	*tmp_node;
	int		pos;
	int		count;

	*stack_a = get_first_node(*stack_a);
	tmp_node = *stack_a;
	tmp_content = tmp_node->content;
	pos = 0;
	count = 0;
	while (tmp_node)
	{
		if (tmp_node->content < tmp_content)
		{
			pos = count;
			tmp_content = tmp_node->content;	
		}
		tmp_node = tmp_node->next;
		count++;
	}
	return (pos);
}

void	push_min(t_list **stack_a, t_list **stack_b, int pos, int len)
{
	if (pos <= (len - 1) / 2)
	{
		while (pos > 0)
		{
			execute(stack_a, stack_b, "ra");
			pos--;
		}
	}
	else
	{
		while (pos < len)
		{
			execute(stack_a, stack_b, "rra");
			pos++;
		}	
	}
	execute(stack_a, stack_b, "pa");
}

void	push_min_to_stack(t_list **stack_a, t_list **stack_b,int len)
{
	int	position;

	if (!stack_a)
		return ;
	while (len > 3)
	{
		position = get_min_position(stack_a);
		push_min(stack_a, stack_b, position, len);
		len--;
	}
}

void sort_for5(t_list **stack_a, t_list **stack_b, int len)
{
	push_min_to_stack(stack_a, stack_b, len);
	sort_for3(stack_a, stack_b);
	while (len > 3)
	{
		execute(stack_a, stack_b, "pb");
		len--;
	}
}

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

void	selection_sort(t_list *stack_a, t_list *stack_b, int *arr, int arr_len)
{
	(void )stack_a;
	(void )stack_b;
	(void )arr;
	(void )arr_len;

}

void	sort(t_list *stack_a, t_list *stack_b, int *arr, int arr_len)
{
	int	i;
	int	step;

	step = 1;
	if (arr_len > 500)
		step = 3;
	else if (arr_len > 300)
		step = 2;
	i = 0;
	while (stack_a && i + step < arr_len)
	{
		if (stack_a->content > arr[i] || stack_a->content > arr[i + step])
		{
			execute(&stack_a, &stack_b, "pa");
			if (stack_a->content > arr[i])
				execute(&stack_a, &stack_b, "rb");
			i++;
		}
		stack_a = stack_a->next;
	}
}


void	push_swap(t_list *stack_a, t_list *stack_b)
{
	int	*sorted_arr;
	int	i;
	int	len;

	stack_a = get_first_node(stack_a);
	len = stack_len(stack_a);
	sorted_arr = (int *)malloc(sizeof(int) * len);
	if (!sorted_arr)
		return ;
	i = 0;
	while (i < len)
	{
		sorted_arr[i] = stack_a->content;
		i++;
		if (stack_a->next)
			stack_a = stack_a->next;
	}
	sorted_arr = sort_arr(sorted_arr, len);
	i = 0;
	// =======for printing array==========
	// while (i < len)
	// {
	// 	printf("%d\n", sorted_arr[i]);
	// 	i++;
	// }
	stack_a = get_first_node(stack_a);
	if (is_sorted(stack_a))
		return ;
	if (len == 2)
		execute(&stack_a, &stack_b, "sa");
	else if (len == 3)
		sort_for3(&stack_a, &stack_b);
	else if (len <= 5)
		sort_for5(&stack_a, &stack_b, len);
	else
		sort(stack_a, stack_b, sorted_arr, len);
	free(sorted_arr);
}
