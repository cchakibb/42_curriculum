#include "../../include/push_swap.h"

static void	rotate(t_stack **stack) //ok
{
	t_stack		*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool print) //ok
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print) //ok
{
	rotate(b);
	if (!print)
		ft_printf("ra\n");
}

void	rr(t_stack **a, t_stack **b, bool print) //ok
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
