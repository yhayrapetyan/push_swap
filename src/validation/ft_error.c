/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:57:02 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 12:57:05 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list *stack_a, char **str)
{
	clean_stack(stack_a);
	if (str)
		free_split(str);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
