/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/02 10:01:19 by chbachir         ###   ########.fr       */
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
	//printf("first_exit_cost = %d\n", first_exit_cost);
	//printf("second_exit_cost = %d\n", second_exit_cost);
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

//void	prepare_stack_a(t_stack **a, int *chunks_arr, int chunk_idx)
void	prepare_stack_a(t_stack **a, int *chunks_arr)
{
	t_stack		*hold_first;
	t_stack		*hold_second;
	int			median;

	median = stack_len(*a) / 2;
	//hold_first = get_hold_first(*a, chunks_arr[chunk_idx], chunk_idx);
	hold_first = get_hold_first(*a, chunks_arr);
	//hold_second = get_hold_second(*a, chunks_arr, chunk_idx);
	hold_second = get_hold_second(*a, chunks_arr);
	//printf("hold first = %d\n", hold_first->nbr);
	//printf("hold second = %d\n", hold_second->nbr);
	a_get_exit_cost_and_move_up(a, hold_first, hold_second, median);
}

t_stack	*get_b_target(int a_nbr, t_stack *b)
{
	t_stack		*target = NULL;

	if (!b)
		return (NULL);
    while(b)
	{
        if(b->nbr < a_nbr && (target == NULL || ((a_nbr - b->nbr) < (a_nbr - target->nbr))))
            target = b;
        b = b->next;
    }
    //if (target)
		//printf("Closest lower number to %d is %d.\n", a_nbr, target->nbr);
	return (target);
}

void	move_b_target_up(t_stack *target, t_stack **b)
{
	if (!(*b) || !target)
		return ;
	int median = stack_len(*b) / 2;

	while (target->idx != 0)
	{
		if (target->idx <= median)
			rb(b);
		else if (target->idx > median)
			rrb(b);
	}
}

void	prepare_stack_b(t_stack **a, t_stack **b)
{
	t_stack		*min_b;
	t_stack		*max_b;
	t_stack		*b_target;

	max_b = get_max(*b);
	min_b = get_min(*b);
	b_target = get_b_target((*a)->nbr, *b);
	if (!(*b) || ((*a)->nbr > max_b->nbr) || ((*a)->nbr < min_b->nbr))
		pb(b, a);
	else
		move_b_target_up(b_target, b);
}

void	sort_stacks(t_stack **a, t_stack **b, int **chunks_arr, \
		int nb_of_chunks)
{
	int	chunk_idx;

	chunk_idx = 0;
	while (chunk_idx < nb_of_chunks)
	{
		while (chunk_value_still_in_a(*a, chunks_arr[chunk_idx]))
		{
			prepare_stack_a(a, chunks_arr[chunk_idx]);
			prepare_stack_b(a, b);
			pb(b, a);
		}
		chunk_idx++;
	}
	while (stack_len(*b) > 0)
		find_max_b_and_pa(a, b);
}



// ./push_swap 8 3 5 11 4 9 6 2 10 1 7 38 -6
// ./push_swap 33 31 30 22 11 17 34 1 39 29 26 23 36 32 7 21 38 24 3 5 37 4 9 35 19 27 25 6 28 2 14 10 8 16 15 18 12 13 20 40
// ./push_swap 5 18 21 23 7 6 22 12 29 2 13 16 38 15 35 30 26 1 8 36 34 27 9 17 39 40 28 31 11 20 4 19 32 24 37 14 25 3 33 10


/* 
TODO
1 . check if candidate hold first/second is chosen correctly if hold_first is head and hold_second is tail, prioritize head because one move only pb()
2 . 


 */
