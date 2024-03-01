/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:20:34 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/28 17:20:36 by yuhayrap         ###   ########.fr       */
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

void	check_for_dublicates(t_list *stack)
{
	int		tmp_content;
	t_list	*tmp_node;

	if (!stack)
		return ; // maybe not?
	stack = get_first_node(stack);
	tmp_node = stack;
	while (tmp_node)
	{
		tmp_content = stack->content;
		while (stack)
		{
			stack = stack->next;
			if (stack && tmp_content == stack->content)
				ft_error(stack, NULL);
		}
		tmp_node = tmp_node->next;
		stack = tmp_node;
	}
}

void	check_for_empty_string(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && ft_strchr(" \n\t\f\v\r", str[i][j])) //maybe more
			j++;
		if (j == ft_strlen(str[i]))
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	ft_check_atoi(const char *str, t_list *stack_a, char **split_result)
{
	long long int	ans;
	int				result;

	ans = 0;
	result = 1;
	while (ft_strchr(" \n\t\f\v\r", *str))
		str++;
	if (*str == '-')
		result *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_error(stack_a, split_result);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			ft_error(stack_a, split_result);
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	if ((result * ans) > 2147483647 || (result * ans) < -2147483648)
		ft_error(stack_a, split_result);
	return (result * ans);
}

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
	// int	sign;

	// sign = 1;
	if (!str)
		return (0);
	if (digit_len(str) > 11)
		return (0);
	if (*str == '-')
	{
		// sign = -1;
		str++;
	}
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
	printf("Error\n");
	system("leaks push_swap");
	exit(EXIT_FAILURE);
}
