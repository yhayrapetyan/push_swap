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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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

// LIST OPERATIONS
void	swap(t_list **stack);
void	rotate(t_list **stack, int reversed);
void	push(t_list **stack_a, t_list **stack_b);
void	execute(t_list **stack_a, t_list **stack_b, char *command, int f);

// STACK OPERATIONS
void	sa(t_list **stack_a, int f);
void	sb(t_list **stack_a, int f);
void	ss(t_list **stack_a, t_list **stack_b, int f);
void	pa(t_list **stack_a, t_list **stack_b, int f);
void	pb(t_list **stack_a, t_list **stack_b, int f);
void	ra(t_list **stack_a, int f);
void	rb(t_list **stack_b, int f);
void	rr(t_list **stack_a, t_list **stack_b, int f);
void	rra(t_list **stack_a, int f);
void	rrb(t_list **stack_b, int f);
void	rrr(t_list **stack_a, t_list **stack_b, int f);

// HELPERS
int		ft_sqrt(int nb);
int		ft_strlen(char *str);
void	free_split(char **str);
int		ft_log2(unsigned int n);
void	print_stack(t_list *stack);//passed without this
int		is_sorted(t_list *stack);
int		ft_pow(int nb, int power);
int		ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	print_2stacks(t_list *stack_a, t_list *stack_b);//passed without this
void	print_2stacks_len(t_list *stack_a, t_list *stack_b);// passed without this

// VALIDATION
int		digit_len(char *str);
int		is_valid_input(char *str);
char	*cut_new_line(char	*command);
int		is_valid_command(char *command);
void	check_for_empty_string(char **str);
void	check_for_dublicates(t_list *stack);
void	ft_error(t_list *stack_a, char **str);
void	fill_stack(t_list **stack_a, int ac, char **av); // also stack operation
int		ft_check_atoi(const char *str, t_list *stack_a, char **split_result);

// SORT
int		get_optimal_step(int len);
int		*sort_arr(int *arr, int n);
int		*sort_arr(int *arr, int n);
int		get_max_position(t_list **stack);
int		get_min_position(t_list **stack_a);
void	push_swap(t_list **stack_a, t_list **stack_b);
void	sort_for3(t_list **stack_a, t_list **stack_b);
int		*fill_arr(t_list *stack, int	*arr, int len);
void	sort_for5(t_list **stack_a, t_list **stack_b, int len);
void	push_max(t_list **stack_a, t_list **stack_b, int pos, int len);
void	push_min(t_list **stack_a, t_list **stack_b, int pos, int len);
void	selection_sort(t_list **stack_a, t_list **stack_b, int arr_len);
void	sort(t_list **stack_a, t_list **stack_b, int *arr, int arr_len);
void	push_2_minimums_from_stack(t_list **stack_a, t_list **stack_b, int len);

// GET NEXT LINE
char	*get_next_line(int fd);
int		ft_strchri(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *str);
char	*get_new_left_str(char *str);

#endif
