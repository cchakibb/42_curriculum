/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:16:09 by chbachir          #+#    #+#             */
/*   Updated: 2024/01/09 14:14:57 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

//***Handle errors //
int				error_input(char *str_n); 
int				duplicates(t_stack *a, int n);
void			free_stack(t_stack **stack);
void			free_error(t_stack **a);

//***Stack initiation
void			init_stack_a(t_stack **a, char **argv);
char			**ft_split(char *s, char c);


//***Nodes initiation
void			init_nodes_a(t_stack *a, t_stack *b);
void			init_nodes_b(t_stack *a, t_stack *b);
void			current_index(t_stack *stack);
void			set_cheapest(t_stack *stack);
t_stack			*get_cheapest(t_stack *stack);
void			prep_for_push(t_stack **s, t_stack *n, char c);

//***Stack utils
int				stack_len(t_stack *stack);
t_stack			*get_last_node(t_stack *stack);
bool			stack_sorted(t_stack *stack);
t_stack			*get_min(t_stack *stack);
t_stack			*get_max(t_stack *stack);

//***Commands
void			sa(t_stack **a, bool print);
void			sb(t_stack **b, bool print);
void			ss(t_stack **a, t_stack **b, bool print);
void			ra(t_stack **a, bool print);
void			rb(t_stack **b, bool print);
void			rr(t_stack **a, t_stack **b, bool print);
void			rra(t_stack **a, bool print);
void			rrb(t_stack **b, bool print);
void			rrr(t_stack **a, t_stack **b, bool print);
void			pa(t_stack **a, t_stack **b, bool print);
void			pb(t_stack **b, t_stack **a, bool print);

//***Algorithm
void			sort_three(t_stack **a);
void			sort_stacks(t_stack **a, t_stack **b);

#endif
