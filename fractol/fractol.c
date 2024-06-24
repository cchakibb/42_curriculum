/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:48:02 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/24 14:09:41 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		start_mlx(&fractal, av);
		mlx_hook(fractal.window, 17, 0, close_fractal, &fractal);
		mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
		mlx_key_hook(fractal.window, key_hook, &fractal);
		render_fractals(&fractal, fractal.name);
		mlx_loop(fractal.mlx);
	}
	else
	{
		write(STDERR_FILENO, "Please Enter:\n", 14);
		write(STDERR_FILENO, "./fractol mandelbrot\n", 21);
		write(STDERR_FILENO, "or\n", 3);
		write(STDERR_FILENO, "./fractol julia [-2...2] [-2...2]\n", 34);
	}
	return (0);
}
