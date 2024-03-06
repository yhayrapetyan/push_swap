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

void	check_result(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) == 1 && stack_len(get_first_node(stack_b)) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	get_input(char *command, t_list **stack_a, t_list **stack_b)
{
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		if (!is_valid_command(command))
		{
			free(command);
			get_next_line(-1);
			ft_error(*stack_a, NULL);
		}
		else
		{
			command = cut_new_line(command);
			execute(stack_a, stack_b, command, 0);
			free(command);
		}
	}
	get_next_line(-1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*command;

	stack_a = NULL;
	stack_b = NULL;
	command = NULL;
	if (ac < 2)
		return (0);
	check_for_empty_string(av);
	fill_stack(&stack_a, ac, av);
	check_for_dublicates(stack_a);
	get_input(command, &stack_a, &stack_b);
	check_result(stack_a, stack_b);
	clean_stack(stack_a);
	clean_stack(stack_b);
	free(command);
	return (0);
}
