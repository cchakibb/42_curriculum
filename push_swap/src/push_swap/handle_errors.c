#include "../../include/push_swap.h"


int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	duplicates(t_stack *a, int n) //ok
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_input(char *cl_nb) //ok
{
	if ( !(is_sign(*cl_nb) || ft_isdigit(*cl_nb)) )
		return (1);
	if ( is_sign(*cl_nb)
		&& !ft_isdigit(cl_nb[1]) )
		return (1);
	while(*++cl_nb)
	{
		if ( !ft_isdigit(*cl_nb) )
			return (1);
	}
	return (0);
}

void	free_stack(t_stack **stack) //ok
{
	t_stack		*temp;
	t_stack		*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->nbr = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_error(t_stack **a) //ok // test *a, should work.
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
