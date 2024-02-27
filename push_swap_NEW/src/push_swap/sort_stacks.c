/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/02/27 12:47:42 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_index(t_stack *stack)
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
}



/* 
void	move_all_to_a(t_stack **a, t_stack **b)
{
	while (stack_len(*b) > 0)
	{
		pa(a, b);
		*b = (*b)->next;
	}
}

void	set_index(t_stack *stack)
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
