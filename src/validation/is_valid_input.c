/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:56:50 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:56:53 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	digit_len(char *str)
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
