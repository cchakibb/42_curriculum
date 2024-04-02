/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:49 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/02 12:00:12 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	error_input(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	duplicates(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (n == a->nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack		*temp;
	t_stack		*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->nbr = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_error(t_stack **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
