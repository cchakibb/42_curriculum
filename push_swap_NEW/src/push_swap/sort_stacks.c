/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/27 19:23:51 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	**create_chunks(t_stack *a, int number_of_chunks)
{
	int			**chunks_arr;
	t_stack		*copy;
	int			i;
	int			j;

	copy = copy_stack(a);
	sort_copy(copy);
	i = 0;
	chunks_arr = (int **)malloc(sizeof(int *) * number_of_chunks);
	while (i < number_of_chunks)
	{
		chunks_arr[i] = (int *)malloc(sizeof(int) * 20);
		i++;
	}
	i = 0;
	j = 0;
	while (copy)
	{
		chunks_arr[i][j] = copy->nbr;
		j++;
		copy = copy->next;
		if (j == 20)
		{
			i++;
			j = 0;
		}
	}
	return (chunks_arr);
}

int	get_hold_first(t_stack *a, int **chunks_arr)
{
	int	hold_first;
	int	found;
	int	i;

	found = 0;
	while (a)
	{
		i = 0;
		while (i < 20)
		{
			if (a && a->nbr == chunks_arr[0][i])
			{
				hold_first = a->nbr;
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

int	get_hold_second(t_stack *a, int **chunks_arr)
{
	int	hold_second;
	int	found;
	int	i;

	found = 0;
	while (a->next)
		a = a->next;
	while (a)
	{
		i = 0;
		while (i < 20)
		{
			if (a && a->nbr == chunks_arr[0][i])
			{
				hold_second = a->nbr;
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
} // stopped here

void	calculate_exit_cost_and_move(t_stack **a, int idx, int median, char *direction_ra, char *direction_rra)
{
	int	exit_cost;
	int	len;

	len = stack_len(*a);
	if (idx <= median)
		exit_cost = idx;
	else
		exit_cost = len - idx;
	if (idx <= median)
		move_to_top(a, exit_cost, direction_ra);
	else
		move_to_top(a, exit_cost, direction_rra);
} // stopped here

void	prepare_stack_a(t_stack **a, int **chunks_arr)
{
	int	hold_first_idx;
	int	hold_second_idx;
	int	hold_first_exit_cost;
	int	hold_second_exit_cost;
	int	median;

	median = stack_len(*a) / 2;
	hold_first_idx = find_index(*a, get_hold_first(*a, chunks_arr));
	hold_second_idx = find_index(*a, get_hold_second(*a, chunks_arr));
	hold_first_exit_cost = hold_first_idx;
	if (hold_first_idx > median)
		hold_first_exit_cost = stack_len(*a) - hold_first_idx;
	hold_second_exit_cost = hold_second_idx;
	if (hold_second_idx > median)
		hold_second_exit_cost = stack_len(*a) - hold_second_idx;
	if (hold_first_exit_cost < hold_second_exit_cost)
		get_exit_cost_and_move(a, hold_first_idx, median, "ra", "rra");
	else
		get_exit_cost_and_move(a, hold_second_idx, median, "ra", "rra");
} // stopped here

void sort_stacks(t_stack **a, t_stack **b, int **chunks_arr)
{

	b = NULL; // temp
	prepare_stack_a(a, chunks_arr);
	 
}

// ./push_swap 8 3 5 11 4 9 6 2 10 1 7 38 -6
// ./push_swap 33 31 30 22 11 17 34 1 39 29 26 23 36 32 7 21 38 24 3 5 37 4 9 35 19 27 25 6 28 2 14 10 8 16 15 18 12 13 20 40
