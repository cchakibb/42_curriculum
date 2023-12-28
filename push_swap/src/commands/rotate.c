#include "../../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	if (!*stack || !(*stack)->next)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}
