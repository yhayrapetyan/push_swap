/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:39:52 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/21 14:39:54 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_node(t_list *node, int content)
{
	t_list	*new;

	new = create_node(content);
	if (new == NULL)
		return (NULL);
	if (node == NULL)
		return (new);
	node->next = new;
	new->prev = node;
	return (new);
}