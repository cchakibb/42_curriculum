/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:05:39 by chbachir          #+#    #+#             */
/*   Updated: 2024/05/02 14:38:20 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int nb_moves = 0;

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			**chunks_arr;

	a = NULL;
	b = NULL;
	chunks_arr = NULL;
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
	//print_stacks(a, b);
	ft_printf("Number of moves: %d\n", nb_moves);
	free_stack(&a);
	return (0);
}

/* 	 TEST
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
	ft_printf("Number of moves: %d\n", nb_moves);

	print_stacks(a, b);
	ft_printf("Number of moves: %d\n", nb_moves);

ARG=""; ./push_swap $ARG | ./checker_linux $ARG

valgrind --leak-check=full ./push_swap -140 -65 -530 364 -498 187 398 -73 417 -340 -203 448 231 143 523 -5 -22 -62 -262 -201 -54 -170 -218 -51 -165 177 245 -239 -316 377 440 100 348 -507 -396 -166 370 -277 -142 -405 158 -362 -135 278 517 535 -479 -423 -134 90 395 116 267 527 -317 518 333 -447 -77 -193 -100 -40 -228 -432 -537 235 66 -331 427 45 -95 492 464 168 -374 -295 -82 -252 -416 -10 424 -380 -441 482 402 -75 8 54 -357 57 -371 -553 -347 31 -481 -126 -278 -68 244 -391    
*/
