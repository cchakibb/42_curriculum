/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:48:25 by chbachir          #+#    #+#             */
/*   Updated: 2024/05/07 10:27:03 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

/*
extern int nb_moves;
*/

typedef struct s_stack
{
	int				nbr;
	int				idx;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// Errors //
int				error_input(char *str_n);
int				duplicates(t_stack *a, int n);
void			free_stack(t_stack **stack);
void			free_error(t_stack **a);
// ______________________________________________________

// Stack utils //
int				stack_len(t_stack *stack);
bool			stack_sorted(t_stack *stack);
t_stack			*get_last_node(t_stack *stack);
t_stack			*get_max(t_stack *stack);
t_stack			*get_min(t_stack *stack);
t_stack			*copy_stack(t_stack *stack);
int				find_index(t_stack *stack, int value);
void			set_index(t_stack *stack);
int				get_median_value(t_stack *stack);
t_stack			*get_hold_first(t_stack *a, int *chunks_arr);
t_stack			*get_hold_second(t_stack *a, int *chunks_arr);
t_stack			*get_b_target(int nbr, t_stack *b);
void			bring_to_top(t_stack *max_b, t_stack **b);
// ______________________________________________________

// Commands
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);

void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);
// ______________________________________________________

// Stack initiation
char			**ft_split(char *s, char c);
void			init_stack_a(t_stack **a, char **av);
int				alloc_chunks_mem(int ***chunks_arr, int nb_of_chunks);
void			free_chunks_arr(int nb_of_chunks, int **chunks_arr);

//______________________________________________________

// Algorithm
void			sort_three(t_stack **a);
void			sort_five(t_stack **a, t_stack **b);
void			sort_small(t_stack **a, t_stack **b);
void			sort_stacks(t_stack **a, t_stack **b, int **chunks_arr);
int				**create_chunks(t_stack *copy, int nb_of_chunks);
void			prepare_stack_a(t_stack **a, int *chunks_arr);
void			prepare_stack_b_and_push(t_stack **a, t_stack **b);
void			move_to_top(t_stack **stack, int cost, char *rotate_type);
void			a_get_exit_cost_and_move_up(t_stack **a, t_stack *hold_first, \
				t_stack *hold_second, int mediane);
int				chunk_value_still_in_a(t_stack *a, int *chunks_arr);
void			move_b_target_up(t_stack *target, t_stack **b);
void			find_max_b_and_pa(t_stack **a, t_stack **b);
void			move_all_to_a(t_stack **a, t_stack **b);

//______________________________________________________

// helper functions
void			print_stacks(t_stack *a, t_stack *b);
//______________________________________________________

void			sort_copy(t_stack *start);
void			swap_copy(t_stack *node_one, t_stack *node_two);

#endif
