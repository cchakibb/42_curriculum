/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/04 14:53:22 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b, int **chunks_arr)
{
	int			chunk_idx;
	int			nb_of_chunks;
	t_stack		*copy;

	copy = copy_stack(*a);
	sort_copy(copy);
	nb_of_chunks = 5;
	if (stack_len(*a) >= 101 && stack_len(*a) <= 500)
		nb_of_chunks = 25;
	chunks_arr = create_chunks(copy, nb_of_chunks);
	chunk_idx = 0;
	while (chunk_idx < nb_of_chunks)
	{
		while (chunk_value_still_in_a(*a, chunks_arr[chunk_idx]))
		{
			prepare_stack_a(a, chunks_arr[chunk_idx]);
			prepare_stack_b_and_push(a, b);
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
