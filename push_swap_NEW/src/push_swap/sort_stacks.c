/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:07:54 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/26 12:25:45 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		**create_chunks(t_stack *a, int number_of_chunks)
{
	int 		**chunks_arr;
	t_stack 	*copy;
	int			chunk_size;

	int			i;
	int			j;
	chunk_size = 20;
	copy = copy_stack(a);
	sort_copy(copy);
	i = 0;
	chunks_arr = (int **)malloc(sizeof(int *) * number_of_chunks);
	while (i < number_of_chunks)
	{
		chunks_arr[i] = (int *)malloc(sizeof(int) * chunk_size);
		i++;
	}

	i = 0;
	j = 0;
	while (copy)
	{
        chunks_arr[i][j] = copy->nbr;
        j++;
        copy = copy->next;
        if (j == chunk_size)
		{
            i++;
            j = 0;
        }
    }
	return (chunks_arr);
}

void sort_stacks(t_stack **a, t_stack **b, int **chunks_arr)
{

	b = NULL; // temp
	int j = 0;
	int hold_first = 0;

	ft_printf("*a = %d\n", (*a)->nbr);
	int x = 0;
	while (a)
	{
		j = 0;
		while (j < 20)
		{
			if (a && (*a)->nbr == chunks_arr[0][j])
			{	
				hold_first = (*a)->nbr;
				break ;
			}
			//ft_printf("comparing chunk = %d with a = %d\n", chunks_arr[0][j], (*a)->nbr);
			printf("chunk = %d, a = %d\n", chunks_arr[0][j], (*a)->nbr);
			j++;
		}
		if (!(*a)->next) break ;
		(*a) = (*a)->next;
		x++;
	}
	ft_printf("*a = %d\n", (*a)->nbr);
	ft_printf("hold 1st = %d\n", hold_first);
}

// ./push_swap 8 3 5 11 4 9 6 2 10 1 7 38 -6

/*
void	split_b(t_stack **a, t_stack **b)
{
	int	compare_iterations;
	int	median;

	median = get_median_value(*b); // gives the median of a sorted copy of 'b' for comparison
	compare_iterations = stack_len(*b);
	while (compare_iterations--)
	{
		if ((*b)->nbr <= median)
			rb(b);
		else
			pa(a, b);
	}
}
*/

/*
void sort_stacks(t_stack **a, t_stack **b)
{
    int chunk_size;
    int total_chunks;
	int chunk_len;
    int i;
	int j;

	chunk_size = 35;
	total_chunks = (stack_len(*a) + chunk_size - 1) / chunk_size;
	i = 0;
    while (i < total_chunks)
    {
		chunk_len = chunk_size;
		if (i == total_chunks - 1)
			chunk_len = (stack_len(*a) % chunk_size);
        if (chunk_len == 0)
            chunk_len = chunk_size;

		j = 0;
        while (j < chunk_len)
        {
            t_stack *min = get_min(*a);
			set_index(*a);
            int min_index = min->index;
            if (min_index <= chunk_len / 2)
            {
                while ((*a)->nbr != min->nbr)
                    ra(a);
            }
            else
            {
                while ((*a)->nbr != min->nbr)
                    rra(a);
            }
            pb(b, a);
			j++;
        }
		i++;
    }
    while (*b != NULL)
        pa(a, b);
}
*/

/*
void	sort_stacks(t_stack **a, t_stack **b)
{
	t_stack		*copy;
	int			compare_iterations;
	int			median;

	copy = copy_stack(*a);
	median = set_index(copy);
	compare_iterations = stack_len(*a);

	while (compare_iterations)
	{
		if ((*a)->nbr >= median)
			ra(a);
		else
			pb(b, a);
		compare_iterations--;
	}

	if (stack_len(*a) > 5)
		sort_stacks(a, b);
	sort_five(a, b);
	print_stacks(*a, *b);
}
*/

/*
void	split_a(t_stack **a, t_stack **b)
{
	int	compare_iterations;
	int	median;

	median = get_median_value(*a); // gives the median of a sorted copy of 'a' for comparison.
	compare_iterations = stack_len(*a);
	while (compare_iterations--)
	{
		if ((*a)->nbr >= median)
			ra(a);
		else
			pb(b, a);
	}
}
*/









