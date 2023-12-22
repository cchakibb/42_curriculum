/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:07:27 by chbachir          #+#    #+#             */
/*   Updated: 2023/12/21 11:14:02 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_btoa(int sig)
{
	static int	bit_index;
	static int	byte;

	if (sig == SIGUSR1)
	{
		byte |= (1 << bit_index);
	}
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", byte);
		bit_index = 0;
		byte = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error");
		return (1);
	}
	pid = getpid();
	ft_printf("Server Process ID = %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
	return (0);
}
