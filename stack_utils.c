/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:18:24 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/12 11:18:26 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->content = content;
	return (node);
}

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

int	stack_len(t_list *stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	clean_stack(t_list *node)
{
	t_list	*next;
	t_list	*prev;
	t_list	*tmp;

	if (node == NULL)
		return ;
	tmp = node->prev;
	printf("prev = %s\n", tmp);
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	while (tmp)
	{
		printf("NOOOOO");
		prev = tmp->prev;
		free(tmp);
		tmp = prev;
	}
}

t_list	*get_first_node(t_list *node)
{
	if (node == NULL)
		return (NULL);
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}

t_list	*get_last_node(t_list *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return node;
}
