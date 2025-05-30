/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:43:01 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 22:16:54 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*start;
	void	*tr_cont;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	start = NULL;
	while (lst)
	{
		tr_cont = f((*lst).content);
		new_node = ft_lstnew(tr_cont);
		if (!new_node)
		{
			del(tr_cont);
			ft_lstclear(&start, del);
			return (start);
		}
		ft_lstadd_back(&start, new_node);
		lst = (*lst).next;
	}
	return (start);
}
