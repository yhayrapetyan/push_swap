/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:40:15 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 14:40:16 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_list *node)
{
	t_list	*next;
	t_list	*prev;
	t_list	*tmp;

	if (node == NULL)
		return ;
	tmp = node->prev;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	while (tmp)
	{
		prev = tmp->prev;
		free(tmp);
		tmp = prev;
	}
}