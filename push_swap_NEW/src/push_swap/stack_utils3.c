/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:49:40 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/28 18:53:54 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_hold_first(t_stack *a, int **chunks_arr, int chunk_idx)
{
	t_stack		*hold_first;
	int			found;
	int			i;

	found = 0;
	while (a)
	{
		i = 0;
		while (i < 20)
		{
			if (a && a->nbr == chunks_arr[chunk_idx][i])
			{
				hold_first = a;
				found = 1;
				break ;
			}
			i++;
		}
		if (!a->next || found)
			break ;
		a = a->next;
	}
	return (hold_first);
}

t_stack	*get_hold_second(t_stack *a, int **chunks_arr, int chunk_idx)
{
	t_stack		*hold_second;
	int			found;
	int			i;

	while (a->next)
		a = a->next;
	found = 0;
	while (a)
	{
		i = 0;
		while (i < 20)
		{
			if (a && a->nbr == chunks_arr[chunk_idx][i])
			{
				hold_second = a;
				found = 1;
				break ;
			}
			i++;
		}
		if (!a->prev || found)
			break ;
		a = a->prev;
	}
	return (hold_second);
}

void	move_to_top(t_stack **a, int exit_cost, char *rotate_type)
{
	int	i;

	if (!a)
		return ;
	i = 0;
	if (ft_strcmp(rotate_type, "ra") == 0)
	{
		while (i++ < exit_cost)
			ra(a);
	}
	else if (ft_strcmp(rotate_type, "rra") == 0)
	{
		while (i++ < exit_cost)
			rra(a);
	}
}

int	chunk_value_still_in_a(t_stack *a, int **chunks_arr, int chunk_idx)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < 20)
		{
			if (a && a->nbr == chunks_arr[chunk_idx][i])
				return (1);
			i++;
		}
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	return (0);
}
