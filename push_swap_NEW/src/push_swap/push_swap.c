/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:05:39 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/04 13:35:13 by chbachir         ###   ########.fr       */
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
		set_index(a);
		set_index(b);
		if (stack_len(a) >= 2 && stack_len(a) <= 5)
			sort_small(&a, &b);
		else
			sort_stacks(&a, &b, chunks_arr);
	}
	t_stack *test = a;
	while (test->next)
	{
		if (test->nbr > test->next->nbr)
		{
			printf("breaking here at %d\n", test->nbr);
			break ;
		}
		test = test->next;
	}
	print_stacks(a, b);
	ft_printf("Number of moves: %d\n", number_of_moves);
	free(chunks_arr);
	free_stack(&a);
	return (0);
}

/* 	// TEST //
	t_stack *test = a;
	while (test->next)
	{
		if (test->nbr > test->next->nbr)
		{
			printf("breaking here at %d\n", test->nbr);
			break ;
		}
		test = test->next;
	}
	print_stacks(a, b);
	ft_printf("Number of moves: %d\n", number_of_moves); */

/* int i = 1;
	t_stack *test = a;
	while (test)
	{
		printf("%d == %d\n", i, test->nbr);
		if (test->nbr != i)
		{
			printf("break here at %d and %d\n", i, test->nbr);
			break ;
		}
		i++;
		test = test->next;
	} */
	//print_stacks(a, b);
	//ft_printf("Number of moves: %d\n", number_of_moves);

//ARG=""; ./push_swap $ARG | ./checker_linux $ARG
