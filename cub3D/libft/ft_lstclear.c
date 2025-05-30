/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:21:29 by stobin            #+#    #+#             */
/*   Updated: 2023/12/04 23:10:56 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		*lst = tmp;
		if ((**lst).content)
			del((**lst).content);
		if ((**lst).next)
			tmp = (**lst).next;
		else
			tmp = NULL;
		free (*lst);
	}
	*lst = NULL;
}
