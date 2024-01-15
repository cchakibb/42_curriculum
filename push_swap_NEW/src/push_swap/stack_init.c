/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:22:17 by chbachir          #+#    #+#             */
/*   Updated: 2024/01/15 13:26:29 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_stack_a(t_stack **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_input(av[i]))
			free_error(a);
		n = ft_atol(av[i]);
	}
}
