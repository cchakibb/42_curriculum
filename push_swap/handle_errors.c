#include "include/push_swap.h"


int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	error_input(char *cl_nb)
{
	if ( !is_sign(cl_nb[0]) ||
		!ft_isdigit(cl_nb[0]) )
		return (1);
	if ( is_sign(cl_nb[0])
		&& !ft_isdigit(cl_nb[1]) )
		return (1);
	while(*++cl_nb)
	{
		if ( !ft_isdigit(*cl_nb) )
			return (1);
	}
	return (0);
}

void	free_error(t_stack_node **a) // test *a, should work.
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
