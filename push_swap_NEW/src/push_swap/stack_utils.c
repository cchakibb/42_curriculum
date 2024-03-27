/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:01:40 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/27 12:31:26 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_index(t_stack *stack, int value)
{
	if (!stack)
		return (-1);
	set_index(stack);
	while (stack)
	{
		if (stack->nbr == value)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

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
		stack = stack->next;
	}
}

int	get_median_value(t_stack *stack) //!
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

int	stack_len(t_stack *stack)
{
	int	len;
	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*get_max(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*get_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	move_all_to_a(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b);
}
