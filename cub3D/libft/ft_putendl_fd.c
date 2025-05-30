/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:24:55 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:44:54 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (*s && fd >= 0)
		ft_putstr_fd(s++, fd);
	write(fd, "\n", 1);
}

/*
int	main(void)
{
	ft_putendl_fd("hello", 1);
	return (0);
}
*/
