/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:18:07 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/12 11:18:08 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		stack_len(t_list *stack);
t_list	*create_node(int content);
void	clean_stack(t_list *node);
t_list	*get_last_node(t_list *node);
t_list	*get_first_node(t_list *node);
t_list	*add_node(t_list *node, int content);

void	print_stack(t_list *stack);
int		is_sorted(t_list *stack);
void	push_swap(t_list *stack_a, t_list *stack_b);
int		ft_strcmp(const char *s1, const char *s2);
int		is_valid_input(char *str);

void	swap(t_list *stack);
void	push(t_list **stack_a, t_list **stack_b);
int		ft_strcmp(const char *s1, const char *s2);
void	rotate(t_list **stack, int reversed);
char	**ft_split(char const *s, char c);

void	sort_for3(t_list *stack_a, t_list *stack_b);
void	sort_for5(t_list *stack_a, t_list *stack_b);
int		*sort_arr(int *arr, int n);
void	selection_sort(t_list *stack_a, t_list *stack_b, int *arr, int arr_len);
void	sort(t_list *stack_a, t_list *stack_b, int *arr, int arr_len);
void	push_swap(t_list *stack_a, t_list *stack_b);
void	swap(t_list *stack);
void	push(t_list **from, t_list **to);
void	rotate(t_list **stack, int reversed);
void	execute(t_list *stack_a, t_list *stack_b, char *command);
void	free_split(char **str);


#endif
