/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:54:56 by chbachir          #+#    #+#             */
/*   Updated: 2023/12/27 17:12:09 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack_node		*a; 
	t_stack_node		*b;

	a = NULL;
	b = NULL;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack_a(&a, av);
	/*if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}*/
	return (0);
}
