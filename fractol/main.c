/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:48:02 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/18 13:48:03 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11) 
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		start_mlx(&fractal, av);
	}

	return (0);
}
