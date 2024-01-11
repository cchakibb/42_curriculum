#include "../../include/push_swap.h"

static void	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;

}

void	sa(t_stack **a, bool print_cmd)
{
	swap(a);
	if (!print_cmd)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print_cmd)
{
	swap(b);
	if (!print_cmd)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print_cmd)
{
	swap(a);
	swap(b);
	if (!print_cmd)
		ft_printf("ss\n");

}
