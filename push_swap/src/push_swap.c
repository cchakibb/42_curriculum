/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:54:56 by chbachir          #+#    #+#             */
/*   Updated: 2023/12/26 16:19:18 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>
#include "../libft/libft.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a, false);
		else if (stack_len(a) == 3)
			small_sort(&a);
		else
			push_swap(&a, &b);
	}
	return (0);
}

