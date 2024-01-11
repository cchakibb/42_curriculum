#include "../../include/push_swap.h"

void	sort_three(t_stack **a) //ok
{
	t_stack *greatest_node;

	greatest_node = get_max(*a);
	if (greatest_node == *a)
		ra(a, false);
	else if ((*a)->next == greatest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
