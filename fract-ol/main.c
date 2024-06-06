/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:28:50 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/04 12:01:27 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//cc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol
void		draw_fractal(t_fractal *fractal, char *name);
static void	init_mlx(t_fractal *fractal, char **av);
static void	init_data(t_fractal *fractal, char **av);

/* 1L<<6: PointerMotionMask, 0L: NoEventMask*/
int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 7))
		|| (4 == ac && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		init_mlx(&fractal, av);
		mlx_key_hook(fractal.window, key_hook, &fractal);
		mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
		mlx_hook(fractal.window, 17, 0, exit_fractal, &fractal);
		draw_fractal(&fractal, fractal.name);
		mlx_loop(fractal.mlx);
	}
	else
	{
		write(STDERR_FILENO, "Please Enter:\n./fractol mandelbrot\n", 31);
		write(STDERR_FILENO, "./fractol julia [-2 < x < 2] [-2 < y < 2]\n", 42);
		exit(EXIT_FAILURE);
	}
	return (0);
}

static void	init_mlx(t_fractal *fractal, char **av)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx,
			SIZE, SIZE, fractal->name);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pixel = mlx_get_data_addr(fractal->image,
			&fractal->bpp,
			&fractal->size_len,
			&fractal->endian);
	init_data(fractal, av);
}

static void	init_data(t_fractal *fractal, char **av)
{
	fractal->max_iter = 42;
	fractal->color = YELLOW;
	fractal->offset_x = -2;
	fractal->offset_y = 2;
	fractal->zoom = 1.0;
	if (!ft_strncmp(av[1], "julia", 6))
	{
		fractal->julia_cx = atodb(av[2]);
		fractal->julia_cy = atodb(av[3]);
	}
	fractal->left_click = 0;
}
