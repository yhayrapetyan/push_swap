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

void	free_split(char **first_arg)
{
	int	i;

	i = 0;
	while (first_arg[i])
	{
		free(first_arg[i]);
		i++;
	}
	free(first_arg[i]);
	free(first_arg);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**first_arg;
	int		i;
	int		j;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		ft_error(stack_a);
	first_arg = NULL;
	j = 0;
	while (ac > 1)
	{
		i = 0;
		ac--;
		first_arg = ft_split(av[ac], ' ');
		if (first_arg == NULL)
			ft_error(stack_a);
		while (first_arg[i] != NULL)
			i++;
		i--;
		while (i >= 0)
		{
			if (!is_valid_input(first_arg[i]))
				ft_error(stack_a);
			stack_a = add_node(stack_a, atoi(first_arg[i]));
			i--;
		}
	}


	free_split(first_arg);
	clean_stack(stack_a);
	clean_stack(stack_b);
	system("leaks a.out");

	return (0);
}
