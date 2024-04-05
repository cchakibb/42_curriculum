/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:01:48 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/05 12:57:38 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("Stack A:\n");
	if (!a)
		ft_printf("Empty\n");
	while (a)
	{
		ft_printf("%d\n", a->nbr);
		a = a->next;
	}
	ft_printf("Stack B:\n");
	if (!b)
		ft_printf("Empty\n");
	while (b)
	{
		ft_printf("%d\n", b->nbr);
		b = b->next;
	}
}
