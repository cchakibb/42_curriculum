/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/28 20:19:53 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	a_get_exit_cost_and_move(t_stack **a, t_stack *first, \
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

void	prepare_stack_a(t_stack **a, int **chunks_arr, int chunk_idx)
{
	t_stack		*hold_first;
	t_stack		*hold_second;
	int			median;

	median = stack_len(*a) / 2;
	hold_first = get_hold_first(*a, chunks_arr, chunk_idx);
	hold_second = get_hold_second(*a, chunks_arr, chunk_idx);
	a_get_exit_cost_and_move(a, hold_first, hold_second, median);
}

t_stack	*get_b_target(int nbr, t_stack *b)
{
	t_stack		*target = NULL;

	if (!b)
		return (NULL);
    while(b)
	{
        if(b->nbr < nbr && (target == NULL || (nbr - b->nbr < nbr - target->nbr)))
            target = b;
        b = b->next;
    } // double check if correct ?
    if(target != NULL)
	{
        printf("Le chiffre le plus proche et inférieur à %d est %d.\n", nbr, target->nbr);
		// find out why this runs infinitely
	}

	return (target);
}

void	move_b_target_up(t_stack *target, t_stack **b)
{
	(void)target;
	(void)b;
	return ;
}

void	prepare_stack_b(t_stack **a, t_stack **b)
{
	t_stack		*max_b;
	t_stack		*min_b;
	t_stack		*b_target;

	max_b = get_max(*b);
	min_b = get_min(*b);
	b_target = get_b_target((*a)->nbr, *b);
	if (!(*b) || ((*a)->nbr > max_b->nbr) || ((*a)->nbr < min_b->nbr))
		pb(b, a);
	else
	{
		move_b_target_up(b_target, b); // needs to be finished.
		// once everything ok next step is to push a->nbr to top of b, and repeat the whole process until chunk1 no longer in 'a'
		// then repeat same thing for other chunks until all 'a' is in 'b'.
	}
	// at the end i need to push to b, pb(b, a), once the target in b is above.
}

void	sort_stacks(t_stack **a, t_stack **b, int **chunks_arr, \
		int nb_of_chunks)
{
	int	chunk_idx;

	chunk_idx = 0;
	while (chunk_idx < nb_of_chunks)
	{
		while (chunk_value_still_in_a(*a, chunks_arr, chunk_idx) == 1) // there is a bug
		{
			prepare_stack_a(a, chunks_arr, chunk_idx); //how many times should that run ?
			prepare_stack_b(a, b); //how many times should that run ?
		}
		chunk_idx++;
	}
}



// ./push_swap 8 3 5 11 4 9 6 2 10 1 7 38 -6
// ./push_swap 33 31 30 22 11 17 34 1 39 29 26 23 36 32 7 21 38 24 3 5 37 4 9 35 19 27 25 6 28 2 14 10 8 16 15 18 12 13 20 40
// ./push_swap 5 18 21 23 7 6 22 12 29 2 13 16 38 15 35 30 26 1 8 36 34 27 9 17 39 40 28 31 11 20 4 19 32 24 37 14 25 3 33 10


/* 
TODO
1 . check if candidate hold first/second is chosen correctly if hold_first is head and hold_second is tail, prioritize head because one move only pb()
2 . 


 */
