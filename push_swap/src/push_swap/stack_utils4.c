/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:44 by chbachir          #+#    #+#             */
/*   Updated: 2024/05/03 13:49:03 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	a_get_exit_cost_and_move_up(t_stack **a, t_stack *first, \
							t_stack *second, int med)
{
	int	first_exit_cost;
	int	second_exit_cost;

	first_exit_cost = first->idx;
	second_exit_cost = second->idx;
	if (first->idx > med)
		first_exit_cost = stack_len(*a) - first->idx;
	if (second->idx > med)
		second_exit_cost = stack_len(*a) - second->idx;
	if (first_exit_cost < second_exit_cost)
	{
		if (first->idx <= med)
			move_to_top(a, first_exit_cost, "ra");
		else
			move_to_top(a, first_exit_cost, "rra");
	}
	else
	{
		if (second->idx <= med)
			move_to_top(a, second_exit_cost, "ra");
		else
			move_to_top(a, second_exit_cost, "rra");
	}
}

void	prepare_stack_a(t_stack **a, int *chunks_arr)
{
	t_stack		*hold_first;
	t_stack		*hold_second;
	int			median;

	median = stack_len(*a) / 2;
	hold_first = get_hold_first(*a, chunks_arr);
	hold_second = get_hold_second(*a, chunks_arr);
	a_get_exit_cost_and_move_up(a, hold_first, hold_second, median);
}

t_stack	*get_b_target(int a_nbr, t_stack *b)
{
	t_stack		*target;

	target = NULL;
	if (!b)
		return (NULL);
	while (b)
	{
		if (b->nbr < a_nbr && (target == NULL \
		|| ((a_nbr - b->nbr) < (a_nbr - target->nbr))))
			target = b;
		b = b->next;
	}
	return (target);
}

void	move_b_target_up(t_stack *target, t_stack **b)
{
	int			median;

	if (!(*b) || !target)
		return ;
	median = stack_len(*b) / 2;
	while (target->idx != 0)
	{
		if (target->idx <= median)
			rb(b);
		else if (target->idx > median)
			rrb(b);
	}
}

void	prepare_stack_b_and_push(t_stack **a, t_stack **b)
{
	t_stack		*b_target;

	b_target = get_b_target((*a)->nbr, *b);
	if (!(*b))
		pb(b, a);
	else
		move_b_target_up(b_target, b);
}
