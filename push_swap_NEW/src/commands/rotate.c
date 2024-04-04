/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:10:21 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/04 12:02:45 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ra(t_stack **a)
{
	rotate(a);
	set_index(*a);
	//ft_printf("ra\n");
	number_of_moves++;
}

void	rb(t_stack **b)
{
	rotate(b);
	set_index(*b);
	//ft_printf("rb\n");
	number_of_moves++;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	set_index(*a);
	set_index(*b);
	//ft_printf("rr\n");
	number_of_moves++;
}
