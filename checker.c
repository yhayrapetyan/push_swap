/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:34:10 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/05 12:34:13 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*command;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	check_for_empty_string(av);
	fill_stack(&stack_a, ac, av);
	check_for_dublicates(stack_a); //maybe need to give &stack_a for leaks
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		if (!is_valid_command(command))
			ft_error(stack_a, NULL);
		else
			execute(&stack_a, &stack_b, cut_new_line(command), 0); //maybe need to execute without write
	}
	// print_2stacks(stack_a, stack_b);
	if (is_sorted(stack_a) == 1 && stack_len(get_first_node(stack_b)) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	clean_stack(stack_a);
	clean_stack(stack_b);
	return (0);
}
