/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:47:06 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/18 14:38:35 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_mlx(t_fractal *fractal, char **av)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, fractal->name);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pixl_addr = mlx_get_data_addr(fractal->image, &fractal->bpp, &fractal->line_size_bytes, &fractal->endian);
	fill_other_data(&fractal, av);
}

void	fill_other_data(t_fractal *fractal, char **av)
{
	fractal->max_fractal_iterations = 40;
	fractal->x_offset = -2;
	fractal->y_offset = 2;
	fractal->zoom = 1.0;
	if (!ft_strncmp(av[1], "julia", 6))
	{
		fractal->julia_c_real = atodb(av[2]);
		fractal->julia_c_imaginary = atodb(av[3]);
	}
}
