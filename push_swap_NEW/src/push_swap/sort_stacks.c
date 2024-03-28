/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/28 12:17:09 by chbachir         ###   ########.fr       */
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

t_stack	*get_hold_first(t_stack *a, int **chunks_arr)
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
			if (a && a->nbr == chunks_arr[0][i])
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

t_stack	*get_hold_second(t_stack *a, int **chunks_arr)
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
			if (a && a->nbr == chunks_arr[0][i])
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
} // stopped here

void	exitcost_and_move(t_stack **a, t_stack *first, t_stack *second, int med)
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

void	prepare_stack_a(t_stack **a, int **chunks_arr)
{
	t_stack		*hold_first;
	t_stack		*hold_second;
	int			median;

	median = stack_len(*a) / 2;
	hold_first = get_hold_first(*a, chunks_arr);
	hold_second = get_hold_second(*a, chunks_arr);
	/*hold_first_exit_cost = hold_first->idx;
	if (hold_first->idx > median)
		hold_first_exit_cost = stack_len(*a) - hold_first->idx;
	hold_second_exit_cost = hold_second->idx;
	if (hold_second->idx > median)
		hold_second_exit_cost = stack_len(*a) - hold_second->idx;
	//if (hold_first_exit_cost < hold_second_exit_cost)
	else REMOVE
		exitcost_and_move(a, hold_second->idx, median, "ra", "rra"); */
	exitcost_and_move(a, hold_first, hold_second, median);
}

void sort_stacks(t_stack **a, t_stack **b, int **chunks_arr)
{

	b = NULL; // temp
	prepare_stack_a(a, chunks_arr);

}

// ./push_swap 8 3 5 11 4 9 6 2 10 1 7 38 -6
// ./push_swap 33 31 30 22 11 17 34 1 39 29 26 23 36 32 7 21 38 24 3 5 37 4 9 35 19 27 25 6 28 2 14 10 8 16 15 18 12 13 20 40
