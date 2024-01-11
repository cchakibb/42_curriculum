#include "../../include/push_swap.h"

static void	rotate_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest_node) //ok
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest_node) //ok
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_cheapest_a_to_b(t_stack **a, t_stack **b) //ok
{
	t_stack		*cheapest_node;

	cheapest_node = get_cheapest(*a); //ok
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both_stacks(a, b, cheapest_node); //ok
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both_stacks(a, b, cheapest_node); //ok
	prep_for_push(a, cheapest_node, 'a'); // *a ? //ok
	prep_for_push(b, cheapest_node->target_node, 'b'); // *a
	pb(b, a, false);
}

static void move_b_to_a(t_stack **a, t_stack **b) //ok
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_stack **a) //ok
{
	while ((*a)->nbr != get_min(*a)->nbr)
	{
		if (get_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack **a, t_stack **b) //ok
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b); // ?
		move_cheapest_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b); // ?
		move_b_to_a(a, b);
	}
	current_index(*a); // ?
	min_on_top(a); // ?
}
