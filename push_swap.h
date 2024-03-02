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

// STACK UTILS
int		stack_len(t_list *stack);
void	clean_stack(t_list *node);
t_list	*create_node(int content);
t_list	*get_last_node(t_list *node);
t_list	*get_first_node(t_list *node);
t_list	*add_node(t_list *node, int content);

// STACK OPERATIONS
void	swap(t_list **stack);
void	rotate(t_list **stack, int reversed);
void	push(t_list **stack_a, t_list **stack_b);
void	execute(t_list **stack_a, t_list **stack_b, char *command);

// HELPERS
int		ft_strlen(char *str);
void	free_split(char **str);
int		is_sorted(t_list *stack);
void	print_stack(t_list *stack);
int		ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	print_2stacks(t_list *stack_a, t_list *stack_b); // need to comment !!!

// VALIDATION
int		digit_len(char *str); //maybe need change to static if not, should include split functions
int		is_valid_input(char *str);
void	check_for_empty_string(char **str);
void	ft_error(t_list *stack_a, char **str);
void	check_for_dublicates(t_list *stack);
int		ft_check_atoi(const char *str, t_list *stack_a, char **split_result);
void	fill_stack(t_list **stack_a, int ac, char **av); // also stack operation

// SORT
int		*sort_arr(int *arr, int n);
int		get_min_position(t_list **stack_a);
void	push_swap(t_list *stack_a, t_list *stack_b);
void	push_swap(t_list *stack_a, t_list *stack_b);
void	sort_for3(t_list **stack_a, t_list **stack_b);
void	sort_for5(t_list **stack_a, t_list **stack_b, int len);
void	sort(t_list **stack_a, t_list **stack_b, int *arr, int arr_len);
void	push_min(t_list **stack_a, t_list **stack_b, int pos, int len);
void	push_2_minimums_from_stack(t_list **stack_a, t_list **stack_b,int len);
void	selection_sort(t_list *stack_a, t_list *stack_b, int *arr, int arr_len);

#endif
