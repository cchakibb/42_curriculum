/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:48:25 by chbachir          #+#    #+#             */
/*   Updated: 2024/02/21 10:28:06 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>


typedef struct s_stack
{
	int				nbr;
	int				index;
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
t_stack			*get_last_node(t_stack *stack);
bool			stack_sorted(t_stack *stack);
t_stack			*get_max(t_stack *stack);
t_stack			*get_min(t_stack *stack);
// ______________________________________________________

// Commands
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
// ______________________________________________________

// Stack initiation
char			**ft_split(char *s, char c);
int				duplicates(t_stack *a, int n);
void			init_stack_a(t_stack **a, char **av);

//______________________________________________________

// Algorithm
void			sort_three(t_stack **a);
void			sort_four(t_stack **a, t_stack **b);
void			sort_five(t_stack **a, t_stack **b);
//void			sort_stacks(t_stack **a, t_stack **b);


// helper
void	print_stacks(t_stack **a, t_stack **b);

#endif
