/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:36:10 by chbachir          #+#    #+#             */
/*   Updated: 2024/04/02 10:25:24 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* int	**create_chunks(t_stack *a, int nb_of_chunks)
{
	int			**chunks_arr;
	t_stack		*copy;
	int			i;
	int			j;

	copy = copy_stack(a);
	sort_copy(copy);
	i = 0;
	chunks_arr = (int **)malloc(sizeof(int *) * nb_of_chunks);
	while (i < nb_of_chunks)
		chunks_arr[i++] = (int *)malloc(sizeof(int) * 20);
	i = 0;
	j = 0;
	while (copy)
	{
		chunks_arr[i][j] = copy->nbr;
		j++;
		copy = copy->next;
		if (j == 20)
		{
			i++;
			j = 0;
		}
	}
	return (chunks_arr);
} */

int **create_chunks(t_stack *a, int nb_of_chunks) {
    int **chunks_arr;
    t_stack *copy;
    int i;
    int j;
    
    copy = copy_stack(a);
    sort_copy(copy);
    
    i = 0;
    chunks_arr = (int **)malloc(sizeof(int *) * nb_of_chunks);
    while (i < nb_of_chunks)
        chunks_arr[i++] = (int *)malloc(sizeof(int) * 20);
    
    i = 0;
    j = 0;
    while (copy)
	{
        if (i >= nb_of_chunks)
            break ;
        chunks_arr[i][j] = copy->nbr;
        j++;
        copy = copy->next;
        if (j == 20)
		{
            i++;
            j = 0;
        }
    }
    return chunks_arr;
}

t_stack	*get_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*get_max(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}


int	get_median_value(t_stack *stack)
{
	t_stack		*copy;
	int			median_value;
	int			median_index;

	copy = copy_stack(stack);
	sort_copy(copy);
	median_index = (stack_len(copy) / 2);
	while (median_index--)
	{
		copy = copy->next;
		median_value = copy->nbr;
	}
	return (median_value);
}

