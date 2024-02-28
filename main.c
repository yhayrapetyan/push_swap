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
	char	**str;
	int		i;
	int		j;

	stack_a = NULL;
	stack_b = NULL;
	str = NULL;
	if (ac < 2)
		ft_error(stack_a, str);
	j = 1;
	check_for_empty_string(av);
	while (j < ac)
	{
		free_split(str);
		i = 0;
		str = ft_split(av[j], ' ');
		if (str == NULL)
			ft_error(stack_a, str);
		while (str[i])
		{
			if (!is_valid_input(str[i]))
				ft_error(stack_a, str);
			stack_a = add_node(stack_a, ft_check_atoi(str[i], stack_a, str));
			i++;
		}
		j++;
	}
	print_2stacks(stack_a, stack_b);
	check_for_dublicates(stack_a, str);
	// push_swap(stack_a, stack_b);

	free_split(str);
	clean_stack(stack_a);
	clean_stack(stack_b);
	system("leaks push_swap");
	return (0);
}
