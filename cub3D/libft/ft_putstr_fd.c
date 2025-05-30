/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:22:55 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:45:02 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s && fd >= 0)
		ft_putchar_fd(*s++, fd);
}

/*
int	main(void)
{
	ft_putstr_fd("helloooo", 1);
	return (0);
}
*/
