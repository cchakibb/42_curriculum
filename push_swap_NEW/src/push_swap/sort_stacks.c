/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/20 15:09:01 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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


void	prepare_stacks(t_stack **a, t_stack **b)
{
	t_stack		*copy_a;
	int			compare_iterations;
	int			median;
	
	copy_a = copy_stack(*a);
	median = set_index(copy_a);
	compare_iterations = stack_len(*a);

	while (compare_iterations)
	{
		if ((*a)->nbr >= median)
			ra(a);
		else
			pb(b, a);
		compare_iterations--;
	}
	// ft_printf("3 - len %d\n", stack_len(*a));
	if (stack_len(*a) > 5)
		prepare_stacks(a, b);
	sort_five(a, b);
	print_stacks(*a, *b);
}




// ./push_swap 8 3 5 11 4 9 6 2 10 1 7 38 -6








