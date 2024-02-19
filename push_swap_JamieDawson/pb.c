/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:09:22 by jadawson          #+#    #+#             */
/*   Updated: 2018/10/16 16:06:16 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_header.h"

void		push_b(t_nums **a, t_nums **b)
{
	t_nums *bot_a;

	if (*a == NULL)
		return ;
	bot_a = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = bot_a;
}