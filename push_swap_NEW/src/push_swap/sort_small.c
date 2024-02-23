/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:32:22 by chbachir          #+#    #+#             */
/*   Updated: 2024/02/23 13:33:40 by chbachir         ###   ########.fr       */
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
