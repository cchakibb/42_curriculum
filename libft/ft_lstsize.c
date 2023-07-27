/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:40:01 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:22:59 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of nodes in a list. */

int	ft_lstsize(t_list *lst)
{
	int	list_length;

	if (!lst)
		return (0);
	list_length = 0;
	while (lst)
	{
		lst = lst->next;
		list_length++;
	}
	return (list_length);
}
