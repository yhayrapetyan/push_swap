/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:20:34 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/28 17:20:36 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_len(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '0' && flag == 0)
		{
			str++;
			continue ;
		}
		str++;
		flag = 1;
		i++;
	}
	return (i);
}

int	is_valid_input(char *str)
{
	if (!str)
		return (0);
	if (digit_len(str) > 11)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || ft_strchr("+-", *str)))
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
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
