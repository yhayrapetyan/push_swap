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

void	ft_error(t_list *stack_a, char **str)
{
	clean_stack(stack_a);
	if (str)
		free_split(str);
	printf("Error\n");
	//system("leaks a.out");
	exit(EXIT_FAILURE);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

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
			stack_a = add_node(stack_a, atoi(str[i]));
			i++;
		}
		j++;
	}
	//push_swap(stack_a, stack_b);
	//stack_b = create_node(0);
	// stack_b = add_node(stack_b, 0);

	print_2stacks(stack_a, stack_b);
	printf("\n\n");
	execute(&stack_a, &stack_b, "pa");
	//execute(&stack_a, &stack_b, "pb");
	// execute(stack_a, stack_b, "pa");
	printf("a = %p\n", stack_a);
	// stack_a = get_first_node(stack_a);
	printf("\n\n");
	print_2stacks(stack_a, stack_b);

	free_split(str);
	// clean_stack(stack_a);
	clean_stack(stack_b);
	system("leaks a.out");
	return (0);
}
