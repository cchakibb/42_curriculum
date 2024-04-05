/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:25:18 by aroque            #+#    #+#             */
/*   Updated: 2024/04/05 09:26:29 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include "push_swap.h"

int number_of_moves = 0;

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	stack = get_stack(argc - 1, &argv[1]);
	index_stack(&stack);
	sort(stack);
	printf("number of moves = %d\n", number_of_moves);
	free_stack(stack);
	return (0);
}
