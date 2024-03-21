/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:56:30 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:56:32 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **stack_a, int ac, char **av)
{
	char	**str;
	int		i;
	int		j;

	if (!stack_a)
		return ;
	j = 1;
	str = NULL;
	while (j < ac)
	{
		free_split(str);
		i = 0;
		str = ft_split(av[j], ' ');
		if (str == NULL)
			ft_error(*stack_a, str);
		while (str[i])
		{
			if (!is_valid_input(str[i]))
				ft_error(*stack_a, str);
			*stack_a = add_node(*stack_a, ft_check_atoi(str[i], *stack_a, str));
			i++;
		}
		j++;
	}
	free_split(str);
}
