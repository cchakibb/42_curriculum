/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:32:22 by chbachir          #+#    #+#             */
/*   Updated: 2024/02/19 21:38:15 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = get_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*max;
	t_stack *min;
	while (stack_len(*a) > 3)
		pb(b, a);
	sort_three(a);
	max = get_max(*a);
	min = get_min(*a);
	while (*b)
	{
		pa(a, b);
		if ((*a)->nbr > max->nbr)
			ra(a);
		if ((*a)->nbr > min->nbr && (*a)->nbr < max->nbr)
	}
}


