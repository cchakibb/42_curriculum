/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/02/23 14:52:38 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	if (!stack)
		return;
	i = 0;
	while (stack)
	{
        stack->index = i;
        ft_printf("i %d = n %d\n", stack->index, stack->nbr);
        stack = stack->next;
		i++;
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	b = NULL; //!
	int			len_a;
	int			mid_stack;
	t_stack		*min_node;
	
	len_a = stack_len(*a);
	mid_stack = len_a / 2;
	min_node = get_min(*a);
	set_index(*a);
}
