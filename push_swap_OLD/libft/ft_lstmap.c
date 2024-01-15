/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:40:00 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:18:08 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the function used to delete the content of a node if needed.
Iterates the list ’lst’ & applies the function ’f’ on the content of eachnode. 
Creates a new list resulting of the successive applications of the function ’f’. 
The ’del’ function is used to delete the content of a node if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&ptr, tmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (ptr);
}
