/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/21 13:48:45 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


int	get_median_value(t_stack *stack)
{
	t_stack		*copy;
	int			median_value;
	int			median_index;

	copy = copy_stack(stack);
	sort_copy(copy);
	median_index = (stack_len(copy) / 2);
	while (median_index--)
	{
		copy = copy->next;
		median_value = copy->nbr;
	}
	return (median_value);
}

void	split_a(t_stack **a, t_stack **b)
{
	int	compare_iterations;
	int	median;

	median = get_median_value(*a);
	compare_iterations = stack_len(*a);
	while (compare_iterations--)
	{
		if ((*a)->nbr >= median)
			ra(a);
		else
			pb(b, a);
	}
}

void	split_b(t_stack **a, t_stack **b)
{
	int	compare_iterations;
	int	median;

	median = get_median_value(*b);
	compare_iterations = stack_len(*b);
	while (compare_iterations--)
	{
		if ((*b)->nbr <= median)
			rb(b);
		else
			pa(a, b);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 3)
		sort_stacks(a, b);
	if (stack_len(*b) > 3)
		sort_stacks(a, b);
}



/*
int	set_index(t_stack *stack)
{
	int	i;
	int	median_index;
	int median_value;

	if (!stack)
		return (-1);
	i = 0;
	sort_copy(stack);
	median_index = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i == median_index)
			median_value = stack->nbr;
		i++;
		stack = stack->next;
	}
	return (median_value);
}
*/

/*
void	sort_stacks(t_stack **a, t_stack **b)
{
	t_stack		*copy;
	int			compare_iterations;
	int			median;

	copy = copy_stack(*a);
	median = set_index(copy);
	compare_iterations = stack_len(*a);

	while (compare_iterations)
	{
		if ((*a)->nbr >= median)
			ra(a);
		else
			pb(b, a);
		compare_iterations--;
	}

	if (stack_len(*a) > 5)
		sort_stacks(a, b);
	sort_five(a, b);
	print_stacks(*a, *b);
}
*/



// ./push_swap 8 3 5 11 4 9 6 2 10 1 7 38 -6








