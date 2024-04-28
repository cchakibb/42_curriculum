/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:05:39 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/09 16:23:04 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int nb_moves = 0;

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
	ft_printf("Number of moves: %d\n", nb_moves);
	free_stack(&a);
	//free(*chunks_arr);
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
	ft_printf("Number of moves: %d\n", nb_moves);

	print_stacks(a, b);
	ft_printf("Number of moves: %d\n", nb_moves);

ARG=""; ./push_swap $ARG | ./checker_linux $ARG

valgrind --leak-check=full ./push_swap -140 -65 -530 364 -498 187 398 -73 417 -340 -203 448 231 143 523 -5 -22 -62 -262 -201 -54 -170 -218 -51 -165 177 245 -239 -316 377 440 100 348 -507 -396 -166 370 -277 -142 -405 158 -362 -135 278 517 535 -479 -423 -134 90 395 116 267 527 -317 518 333 -447 -77 -193 -100 -40 -228 -432 -537 235 66 -331 427 45 -95 492 464 168 -374 -295 -82 -252 -416 -10 424 -380 -441 482 402 -75 8 54 -357 57 -371 -553 -347 31 -481 -126 -278 -68 244 -391    

==19447== HEAP SUMMARY:
==19447==     in use at exit: 2,816 bytes in 105 blocks
==19447==   total heap usage: 206 allocs, 102 frees, 5,240 bytes allocated
==19447== 
==19447== 440 (40 direct, 400 indirect) bytes in 1 blocks are definitely lost in loss record 2 of 4
==19447==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==19447==    by 0x40294B: alloc_chunks_mem (in /home/chbachir/Code/eval/carina/push_swap)
==19447==    by 0x402A3A: create_chunks (in /home/chbachir/Code/eval/carina/push_swap)
==19447==    by 0x4023B2: sort_stacks (in /home/chbachir/Code/eval/carina/push_swap)
==19447==    by 0x4020BA: main (in /home/chbachir/Code/eval/carina/push_swap)
==19447== 
==19447== 2,376 (24 direct, 2,352 indirect) bytes in 1 blocks are definitely lost in loss record 4 of 4
==19447==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==19447==    by 0x401950: copy_stack (in /home/chbachir/Code/eval/carina/push_swap)
==19447==    by 0x40235F: sort_stacks (in /home/chbachir/Code/eval/carina/push_swap)
==19447==    by 0x4020BA: main (in /home/chbachir/Code/eval/carina/push_swap)
==19447== 
==19447== LEAK SUMMARY:
==19447==    definitely lost: 64 bytes in 2 blocks
==19447==    indirectly lost: 2,752 bytes in 103 blocks
==19447==      possibly lost: 0 bytes in 0 blocks
==19447==    still reachable: 0 bytes in 0 blocks
==19447==         suppressed: 0 bytes in 0 blocks
*/
