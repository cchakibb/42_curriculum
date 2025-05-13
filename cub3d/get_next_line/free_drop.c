/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_drop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:49:50 by stobin            #+#    #+#             */
/*   Updated: 2024/06/15 22:53:30 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_drop(t_glist *tail, t_glist **chunk)
{
	free(tail);
	tail = NULL;
	drop_chunks(*chunk);
}

void	free_tail(t_glist *tail)
{
	free(tail);
	tail = NULL;
}
