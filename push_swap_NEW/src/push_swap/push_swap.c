/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:05:39 by chbachir          #+#    #+#             */
/*   Updated: 2024/01/30 13:49:19 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main (int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	
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
		{
			//
		}
	}
	free_stack(&a);
	return (0);
}
