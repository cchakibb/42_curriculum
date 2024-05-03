/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:21:20 by chbachir          #+#    #+#             */
/*   Updated: 2024/05/03 13:47:57 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_copy(t_stack *node_one, t_stack *node_two)
{
	int	temp;

	temp = node_one->nbr;
	node_one->nbr = node_two->nbr;
	node_two->nbr = temp;
}

void	sort_copy(t_stack *copy)
{
	int			swapped;
	t_stack		*ptr1;
	t_stack		*lptr;

	lptr = NULL;
	if (copy == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = copy;
		while (ptr1->next != lptr)
		{
			if (ptr1->nbr > ptr1->next->nbr)
			{
				swap_copy(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

t_stack	*copy_stack(t_stack *a)
{
	t_stack		*new_head;
	t_stack		**current;
	t_stack		*tmp;

	new_head = NULL;
	current = &new_head;
	while (a)
	{
		*current = malloc(sizeof(t_stack));
		if (!*current)
		{
			while (new_head)
			{
				tmp = new_head;
				new_head = new_head->next;
				free(tmp);
			}
			return (NULL);
		}
		(*current)->nbr = a->nbr;
		(*current)->next = NULL;
		current = &((*current)->next);
		a = a->next;
	}
	return (new_head);
}
