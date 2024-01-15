/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:14 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:04:03 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
Adds the node ’new’ at the end of the list
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back = ft_lstlast(*lst);
	back->next = new;
}
