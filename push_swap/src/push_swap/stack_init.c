#include "../../include/push_swap.h"

static long	ft_atol(const char *s) //ok
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while ( ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack **stack, int n) //ok
{
	t_stack		*node;
	t_stack		*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		last_node->prev = last_node;
	}
}

void	init_stack_a(t_stack **a, char **av) //ok
{
	long	n;
	int		i;

	i = 0;
	while(av[i])
	{
		if (error_input(av[i]))
			free_error(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (duplicates(*a, (int)n))
			free_error(a);
		append_node(a, (int)n);
		i++;
	}
}

t_stack	*get_cheapest(t_stack *stack) //ok
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name) //ok
{
	while (*stack != top_node)
	{
		if ('a' == stack_name)
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if ('b' == stack_name)
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
