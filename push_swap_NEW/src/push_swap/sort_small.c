/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:32:22 by chbachir          #+#    #+#             */
/*   Updated: 2024/02/21 21:44:06 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max_node;

	max_node = get_max(*a);
	if (max_node == *a)
		ra(a);
	else if ((*a)->next == max_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack		*current;
	t_stack		*compare;
	int 		count;

	current = *a;
	while (stack_len(*a) > 3)
	{
		count = 0;
		compare = (*a)->next;
		while (compare)
		{
			if (current->nbr < compare->nbr)
				count++;
			compare = compare->next;
		}
		if (count >= 3)
				pb(b, a);
		else
			ra(a);
		current = *a;
	}
	if (!stack_sorted(*a))
		sort_three(a);
	if ((*b)->nbr < (*b)->next->nbr) // dont do if sorting 4
		sb(b);
	pa(a, b);
	pa(a, b); // dont push if sorting 4
	print_stacks(*a, *b);
}
	
