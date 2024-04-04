/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:54:32 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/04 12:02:29 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	//review
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	set_index(*a);
	//ft_printf("rra\n");
	number_of_moves++;
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	set_index(*b);
	//ft_printf("rrb\n");
	number_of_moves++;
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	set_index(*a);
	set_index(*b); 
	//ft_printf("rrr\n");
	number_of_moves++;
}
