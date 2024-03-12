/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:32:22 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/12 11:31:16 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack		*max_node;

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
	t_stack		*compare;
	int			count;

	while (stack_len(*a) > 3)
	{
		count = 0;
		compare = (*a)->next;
		while (compare)
		{
			count += ((*a)->nbr < compare->nbr);
			compare = compare->next;
		}
		if (count >= 3)
			pb(b, a);
		else
			ra(a);
	}
	sort_three(a);
	if (stack_len(*b) == 2 && (*b)->nbr < (*b)->next->nbr)
		sb(b);
	if (stack_len(*b) == 2)
		pa(a, b);
	pa(a, b);
}

void	rev_sort_three(t_stack **a)
{
	t_stack		*min_node;

	min_node = get_min(*a); // Assuming get_min is similar to get_max but for the minimum
	if (min_node == *a)
		ra(a); // Rotate upwards
	else if ((*a)->next == min_node)
		rra(a); // Rotate downwards
	if ((*a)->nbr < (*a)->next->nbr) // Change comparison for greater to lesser
		sa(a); // Swap if not in order
}

void	rev_sort_five(t_stack **a, t_stack **b)
{
	t_stack		*compare;
	int		count;

	while (stack_len(*a) > 3)
	{
		count = 0;
		compare = (*a)->next;
		while (compare)
		{
			count += ((*a)->nbr > compare->nbr); // Change condition to count how many are lesser
			compare = compare->next;
		}
		if (count >= 3)
			pb(b, a); // Push to stack b if it's one of the larger numbers
		else
			ra(a); // Otherwise, rotate
	}
	rev_sort_three(a); // Sort the top three now correctly for greater to lesser
	if (stack_len(*b) == 2 && (*b)->nbr > (*b)->next->nbr) // Adjust for greater to lesser
		sb(b); // Swap b if not in order (greater to lesser)
	if (stack_len(*b) == 2)
		pa(a, b); // Push the first number from b to a
	pa(a, b); // Push the remaining number from b to a, completing the sort
}
