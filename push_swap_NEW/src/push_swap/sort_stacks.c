/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/12 11:46:30 by chbachir         ###   ########.fr       */
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
	median_index = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < median_index)
			stack->below_median = true;
		else if (i == median_index)
		{
			median_value = stack->nbr;
			stack->below_median = true;
		}
		else
			stack->below_median = false;
		i++;
		//ft_printf("i %d = n %d\n", stack->index, stack->nbr);
		stack = stack->next;
	}
	return (median_value);
}

void sort_stacks(t_stack **a, t_stack **b)
{
	t_stack		*copy;
	int			copy_median;
	int			a_median;
	int			iterations;

	copy = copy_a(*a);
	sort_copy(copy);
	a_median = set_index(*a);
	copy_median = set_index(copy);
	iterations = stack_len(*a);
	while (iterations)
	{
		if ((*a)->nbr <= copy_median) 
			pb(b, a);
		else
			ra(a);
		/*else if ((*a)->index <= (stack_len(*a) / 2))
			ra(a);
		else
			rra(a);*/
		iterations--;
	}
	sort_three(a);
	rev_sort_five(b, a);
	move_all_to_a(a, b);
	print_stacks(*a, *b);
	// stopped here
}


/* void	set_index(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		//ft_printf("i %d = n %d\n", stack->index, stack->nbr);
		stack = stack->next;
	}
}

void	sort_one_hundred(t_stack **a, t_stack **b)
{
	int	mid_stack;

	set_index(*a);
	mid_stack = stack_len(*a) / 2;

	while ((*a)->index < mid_stack)
			pb(b, a);
} */




void	move_all_to_a(t_stack **a, t_stack **b)
{
	while (stack_len(*b) > 0)
	{
		pa(a, b);
	}
}

/*void	set_index(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack)
	{
		i++;
		stack->index = i;
		//ft_printf("i %d = n %d\n", stack->index, stack->nbr);
		stack = stack->next;
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int			len_a;
	int			mid_stack;
	t_stack		*min_node;

	len_a = stack_len(*a);
	mid_stack = len_a / 2;
	set_index(*a);
	
	
	while (stack_len(*a) >= 1)
	{
		min_node = get_min(*a);
		if (len_a % 2 == 0)
		{
			while ((*a)->nbr != min_node->nbr)
			{
				if (min_node->index > mid_stack)
					rra(a);
				else
					ra(a);
				set_index(*a);
			}
		}
		if (len_a % 2 == 1)
		{
			while ((*a)->nbr != min_node->nbr)
			{
				if (min_node->index > mid_stack + 1)
					rra(a);
				else
					ra(a);
				set_index(*a);
			}
		}
		pb(b, a);
	}
	move_all_to_a(a, b);
} */
