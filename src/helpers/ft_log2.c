/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:42:08 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:42:10 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_log2(unsigned int n)
{
	int	result;

	result = -1;
	while (n)
	{
		n >>= 1;
		result++;
	}
	return (result);
}