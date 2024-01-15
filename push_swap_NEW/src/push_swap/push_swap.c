/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:05:39 by chbachir          #+#    #+#             */
/*   Updated: 2024/01/15 13:21:32 by chbachir         ###   ########.fr       */
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
	
	
}
