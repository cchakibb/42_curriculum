/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:50:52 by stobin            #+#    #+#             */
/*   Updated: 2023/12/04 23:04:35 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	if (lst != NULL)
		i = 1;
	while ((*lst).next)
	{
		i++;
		lst = (*lst).next;
	}
	return (i);
}
