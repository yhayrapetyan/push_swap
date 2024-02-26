#include "push_swap.h"

void	print_stack(t_list *stack)
{
	int	i;

	// stack = get_first_node(stack);
	while (stack)
	{
		i = 0;
		// printf("%d", stack->content);
		if (stack->content < 0)
		{
			stack->content *= -1;
			printf("minus");
		}
		while (i < stack->content)
		{
			printf("*");
			i++;
		}
		printf("\n");
		stack = stack->next;
	}
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
