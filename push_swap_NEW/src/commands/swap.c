/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:05:40 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/03 14:50:31 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack **head)
{
	if (!(*head) || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a)
{
	swap(a);
	set_index(*a);
	ft_printf("sa\n");
	number_of_moves++;
}

void	sb(t_stack **b)
{
	swap(b);
	set_index(*b);
	ft_printf("sb\n");
	number_of_moves++;
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	set_index(*a);
	set_index(*b);
	ft_printf("ss\n");
	number_of_moves++;
}
