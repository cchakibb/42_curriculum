/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:48:25 by chbachir          #+#    #+#             */
/*   Updated: 2024/01/30 11:21:16 by chbachir         ###   ########.fr       */
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
// ______________________________________________________

// Commands
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
// ______________________________________________________

char			**ft_split(char *s, char c);
int				duplicates(t_stack *a, int n);
void			init_stack_a(t_stack **a, char **av);

#endif
