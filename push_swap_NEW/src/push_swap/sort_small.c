/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:32:22 by chbachir          #+#    #+#             */
/*   Updated: 2024/02/21 14:46:04 by chbachir         ###   ########.fr       */
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

/* void	sort_four(t_stack **a, t_stack **b)
{
	
} */


void	sort_five(t_stack **a, t_stack **b)
{
	int 		count;
	t_stack		*compare;

	compare = (*a)->next;
	while (stack_len(*a) > 3)
	{
		count = 0;
		while (compare->next)
		{
			if ((*a)->nbr < compare->nbr)
				count++;
			compare = (*a)->next;
		}
		if (count >= 3)
			{
				pb(b, a);
				break ;
			}
		else
			ra(a);
	}
}
		/* compare = (*a)->next->nbr;
		if ((*a)->nbr < compare)
		{
			count++;
		}
		if (count >= 3)
		{
			count = 0;
			pb(b, a);
		}
		else
		{
			count = 0;
			ra(a);
		} */
		

	// int count
	// int i;

	// i = 0;
	// while (i < 5 && stack_len(*b) < 3)
	// {
    //     count = 0;
    //     if ((*a)->next && (*a)->nbr < (*a)->next->nbr)
    //         count++;
    //     if ((*a)->next->next && (*a)->nbr < (*a)->next->next->nbr)
    //         count++;
    //     if ((*a)->next->next->next && ((*a)->nbr < (*a)->next->next->next->nbr))
    //         count++;
    //     if (((*a)->next->next->next->next) && (i < 4) && ((*a)->nbr < (*a)->next->next->next->next->nbr))
    //         count++;
    //     if (count < 3)
    //         ra(a);
    //     else if (count >= 3)
	// 		pb(b, a);
	// 	i++; 
    // }

	//print_stacks(a, b);

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
	}*/


