#include "include/push_swap.h"


int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	error_input(char *cl_nb)
{
	if ( !is_sign(*cl_nb) ||
		!ft_isdigit(*cl_nb) )
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
