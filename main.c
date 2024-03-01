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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		ft_error(stack_a, NULL);
	check_for_empty_string(av);
	fill_stack(&stack_a, ac, av);
	check_for_dublicates(stack_a);
	push_swap(stack_a, stack_b);

	print_2stacks(stack_a, stack_b);

	clean_stack(stack_a);
	clean_stack(stack_b);
//	system("leaks push_swap");
	return (0);
}
