/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:49 by chbachir          #+#    #+#             */
/*   Updated: 2024/01/30 11:16:04 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	error_input(char *str_n) //handles syntax errors, returns `1` for `error` should any of the following conditions are met
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}

int	duplicates(t_stack *a, int n) //checks for duplicate input numbers in stack `a`
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

void	free_stack(t_stack **stack) //free a stack if there are errors
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

void	free_error(t_stack **a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
