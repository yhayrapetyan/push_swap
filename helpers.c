#include "push_swap.h"

void	print_stack(t_list *stack)
{
	int	i;

	stack = get_first_node(stack);
	while (stack)
	{
		i = 0;
		printf("%d", stack->content);
		// if (stack->content < 0)
		// {
		// 	stack->content *= -1;
		// 	printf("minus");
		// }
		// while (i < stack->content)
		// {
		// 	printf("*");
		// 	i++;
		// }
		printf("\n");
		stack = stack->next;
	}
}

void	print_2stacks(t_list *stack_a, t_list *stack_b)
{
	stack_a = get_first_node(stack_a);
	stack_b = get_first_node(stack_b);
	printf("=~=~==~==~==~==~==~==~==~==~==~==~==~==~==~==~=~\n");
	printf("                 PRINTING STACKS                \n");
	printf("=~=~==~==~==~==~==~==~==~==~==~==~==~==~==~==~=~\n");
	if (stack_a)
	{
		printf("STACK A");
		if (stack_b)
		{
			printf("\t\tSTACK B");
		}
		printf("\n");
		while (stack_a)
		{
			printf("%d", stack_a->content);
			if (stack_b)
			{
				printf("\t\t%d", stack_b->content);
				stack_b = stack_b->next;
			}
			printf("\n");
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			printf("\t\t%d", stack_b->content);
			stack_b = stack_b->next;
			printf("\n");
		}
	}
	else
	{

		printf("STACK B\n");
		while (stack_b)
		{
			printf("%d\n", stack_b->content);
			stack_b = stack_b->next;
		}
	}
	printf("================================================\n");
	printf("================================================\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_sorted(t_list *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
