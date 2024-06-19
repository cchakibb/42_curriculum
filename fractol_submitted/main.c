/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:00:21 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/14 12:00:22 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_fractal(t_fractal *fractal, char *name);
static void	init_mlx(t_fractal *fractal, char **av);
static void	init_other_data(t_fractal *fractal, char **av);

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 11))
		|| (4 == ac && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		init_mlx(&fractal, av);
		mlx_hook(fractal.window, 17, 0, exit_fractal, &fractal);
		mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
		mlx_key_hook(fractal.window, key_hook, &fractal);
		draw_fractal(&fractal, fractal.name);
		mlx_loop(fractal.mlx);
	}
	else
	{
		write(STDERR_FILENO, "Please Enter:\n", 14);
		write(STDERR_FILENO, "./fractol mandelbrot\n", 21);
		write(STDERR_FILENO, "or\n", 3);
		write(STDERR_FILENO, "./fractol julia [-2...2] [-2...2]\n", 34);
		exit(EXIT_FAILURE);
	}
	return (0);
}

static void	init_mlx(t_fractal *fractal, char **av)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->window = mlx_new_window(fractal->mlx,
			SIZE, SIZE, fractal->name);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pixel_addr = mlx_get_data_addr(fractal->image,
			&fractal->bpp,
			&fractal->size_len,
			&fractal->endian);
	init_other_data(fractal, av);
}

static void	init_other_data(t_fractal *fractal, char **av)
{
	fractal->max_iter = 35;
	fractal->color = ORANGE;
	fractal->offset_x = -2;
	fractal->offset_y = 2;
	fractal->zoom = 1.0;
	if (!ft_strncmp(av[1], "julia", 6))
	{
		fractal->julia_cx = atodb(av[2]);
		fractal->julia_cy = atodb(av[3]);
	}
}
