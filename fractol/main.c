/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:48:02 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/19 23:20:53 by chbachir         ###   ########.fr       */
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
		mlx_key_hook(fractal.window, key_hook, &fractal);
		mlx_hook(fractal.window, 17, 0, close_fractal, &fractal);
		render_fractals(&fractal, fractal.name); ////// BUG /////////
		mlx_loop(fractal.mlx);
	}

	return (0);
}
