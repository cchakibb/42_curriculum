/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/12 14:22:15 by chbachir         ###   ########.fr       */
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
	free_stack(&copy);
	while (stack_len(*b) > 0)
		find_max_b_and_pa(a, b);

	while (nb_of_chunks > 0)
	{
		free(chunks_arr[nb_of_chunks--]);
	}
	chunks_arr = NULL;
}
