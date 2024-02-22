/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:27:57 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/10 18:27:59 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(char *str)
{
	int	sign;

	sign = 1;
	if (!str)
		return (0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	ft_error(t_list *stack_a)
{
	clean_stack(stack_a);
	printf("Error\n");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		ft_error(stack_a);
	while (ac > 1)
	{
		ac--;
		if (!is_valid_input(av[ac]))
			ft_error(stack_a);
		stack_a = add_node(stack_a, atoi(av[ac]));
	}
	// push_swap(stack_a, stack_b);
	printf("before rotate ================\n");
	print_stack(stack_a);
	rotate(&stack_a, 0);
	printf("after rotate ================\n");
	print_stack(stack_a);
	return (0);
}
