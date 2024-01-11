#include "../../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	if (!*stack || !(*stack)->next)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

static void	rotate_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	ft_printf("ra\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}