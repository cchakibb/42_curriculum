/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:32:22 by chbachir          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:13 by chbachir         ###   ########.fr       */
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
	int		count;
	t_stack	*next;
	b = NULL;
	count = 0;
	next = (*a)->next;
	while (a)
	{
		if ((*a)->nbr < (*a)->next->nbr)
			count++;	
		a = &(*a)->next;
	}
	ft_printf("counter %d", count);
}


	
/*	t_stack	*max;
	t_stack *min;
	t_stack *mid_a_node;
	while (stack_len(*a) > 3)
		pb(b, a);
	sort_three(a);
	max = get_max(*a); // 3
	min = get_min(*a); // 9
	mid_a_node = (*a)->next;
 	while (*b)
	{

		if ((*b)->nbr > max->nbr)
		{
			pa(a, b);
			ra(a);
		}
		else if (((*b)->nbr > min->nbr && (*b)->nbr < max->nbr) && 
		(*b)->nbr < mid_a_node->nbr)
		{
			ra(a);
			pa(a, b);
			rra(a);
			//pa(a, b);
			
		}
		else if ((*b)->nbr > min->nbr && (*b)->nbr < max->nbr)
		{
			rra(a);
			pa(a, b);
			ra(a);
			ra(a);
		}
		else
			pa(a, b);
	} */


