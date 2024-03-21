/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:40:26 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 14:40:27 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_first_node(t_list *node)
{
	if (node == NULL)
		return (NULL);
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}
