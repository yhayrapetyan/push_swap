/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:56:15 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:56:16 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
