/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:05:39 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/27 15:58:55 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int number_of_moves = 0;

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			**chunks_arr;

	chunks_arr = NULL;
	a = NULL;
	b = NULL;
	if (1 == ac || (2 == ac && !av[1][0]))
		return (1);
	else if (2 == ac)
		av = ft_split(av[1], ' ');
	init_stack_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) == 4 || stack_len(a) == 5)
			sort_five(&a, &b);
		else if (stack_len(a) <= 100)
		{
			chunks_arr = create_chunks(a, 5);
			sort_stacks(&a, &b, chunks_arr);
		}
		else if (stack_len(a) <= 500)
		{
			chunks_arr = create_chunks(a, 11);
			sort_stacks(&a, &b, chunks_arr);
		}
	}
	print_stacks(a, b);
	//ft_printf("Number of moves: %d\n", number_of_moves);
	free(chunks_arr);
	free_stack(&a);
	return (0);
}

